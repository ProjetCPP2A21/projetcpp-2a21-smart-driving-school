#include "empriente.h"
#include <QDebug>
#include <QSettings>
#include <QtSerialPort/QSerialPortInfo>
#include <QInputDialog>
#include <QSqlQuery>
#include <QSqlError>

Empriente::Empriente(QObject *parent)
    : QObject(parent),
    arduino(new QSerialPort(this))
{
}

bool Empriente::connecterArduino()
{
    QSettings settings;
    QString configured = settings.value("Arduino/Port").toString().trimmed();
    QString envPort = QString::fromUtf8(qgetenv("ARDUINO_PORT")).trimmed();
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    QStringList candidates;
    if (!envPort.isEmpty()) candidates << envPort;
    candidates << QStringLiteral("COM3");
    if (!configured.isEmpty()) candidates << configured;
    for (const QSerialPortInfo &info : ports) {
        QString name = info.portName();
        QString desc = info.description();
        QString manu = info.manufacturer();
        bool match = desc.contains("Arduino", Qt::CaseInsensitive) || manu.contains("Arduino", Qt::CaseInsensitive) || desc.contains("CH340", Qt::CaseInsensitive) || manu.contains("wch", Qt::CaseInsensitive) || desc.contains("USB-SERIAL", Qt::CaseInsensitive);
        if (match && !candidates.contains(name)) candidates << name;
    }
    for (const QSerialPortInfo &info : ports) {
        QString name = info.portName();
        if (!candidates.contains(name)) candidates << name;
    }
    for (const QString &portName : candidates) {
        if (arduino->isOpen()) { arduino->close(); }
        arduino->clearError();
        arduino->setPortName(portName);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        if (arduino->open(QIODevice::ReadWrite)) {
            connect(arduino, &QSerialPort::readyRead, this, &Empriente::lirePort);
            qDebug() << "Arduino connecte" << portName;
            m_port = portName;
            settings.setValue("Arduino/Port", portName);
            return true;
        } else {
            m_lastError = arduino->errorString();
            qDebug() << "Echec ouverture" << portName << m_lastError;
        }
    }
    if (!ports.isEmpty()) {
        QStringList names;
        for (const QSerialPortInfo &info : ports) names << info.portName();
        bool ok = false;
        QString choice = QInputDialog::getItem(nullptr, "Sélection du port Arduino", "Port:", names, 0, false, &ok);
        if (ok && !choice.isEmpty()) {
            if (arduino->isOpen()) { arduino->close(); }
            arduino->clearError();
            arduino->setPortName(choice);
            arduino->setBaudRate(QSerialPort::Baud9600);
            arduino->setDataBits(QSerialPort::Data8);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
            arduino->setFlowControl(QSerialPort::NoFlowControl);
            if (arduino->open(QIODevice::ReadWrite)) {
                connect(arduino, &QSerialPort::readyRead, this, &Empriente::lirePort);
                qDebug() << "Arduino connecte" << choice;
                m_port = choice;
                settings.setValue("Arduino/Port", choice);
                return true;
            } else {
                m_lastError = arduino->errorString();
                qDebug() << "Echec ouverture" << choice << m_lastError;
            }
        }
    }
    m_lastError = arduino->errorString();
    qDebug() << "Erreur connexion Arduino" << m_lastError;
    return false;
}

void Empriente::envoyerCommande(QString cmd)
{
    if (arduino->isOpen()) {
        arduino->write(cmd.toUtf8());
    }
}

void Empriente::lireDonnees()
{
    QByteArray data = arduino->readAll();
    QString msg = QString::fromUtf8(data).trimmed();

    if (!msg.isEmpty()) {
        quint32 id = convertirCodeHexEnDecimal(msg.toUtf8());
        if (id == 0) {
            qDebug() << "Empreinte reçue (hex):" << msg << ", conversion invalide";
            emit fingerprintResult(QStringLiteral("n'est pas inscrit"));
            return;
        }
        bool ok = verifierIDDansBase(id);
        qDebug() << "Empreinte ID décimal:" << id << (ok ? "→ inscrit" : "→ n'est pas inscrit");
        emit fingerprintResult(ok ? QStringLiteral("inscrit") : QStringLiteral("n'est pas inscrit"));
    }
}

void Empriente::lirePort()
{
    static QByteArray buffer;
    buffer += arduino->readAll();

    while (buffer.contains('\n')) {
        int index = buffer.indexOf('\n');
        QByteArray line = buffer.left(index).trimmed();
        buffer.remove(0, index + 1);

        QString data = QString::fromUtf8(line);
        qDebug() << "Reçu:" << data;

        if (data.startsWith(QStringLiteral("FINGER:FOUND"))) {
            QStringList parts = data.split(';');
            if (parts.size() >= 2 && parts[1].startsWith(QStringLiteral("ID:"))) {
                bool okId = false;
                int id = parts[1].mid(3).toInt(&okId);
                if (okId) {
                    qDebug() << "ID reconnu =" << id;
                    bool inscrit = verifierIDDansBase(static_cast<quint32>(id));
                    qDebug() << (inscrit ? "→ inscrit" : "→ n'est pas inscrit");
                    emit fingerprintResult(inscrit ? QStringLiteral("inscrit") : QStringLiteral("n'est pas inscrit"));
                } else {
                    qDebug() << "ID invalide dans trame:" << parts.value(1);
                    emit fingerprintResult(QStringLiteral("n'est pas inscrit"));
                }
            } else {
                qDebug() << "Trame FINGER:FOUND mal formée:" << data;
                emit fingerprintResult(QStringLiteral("n'est pas inscrit"));
            }
        } else if (data == QStringLiteral("FINGER:NOTFOUND")) {
            qDebug() << "Empreinte non trouvée";
            emit fingerprintResult(QStringLiteral("n'est pas inscrit"));
        } else {
            // Fallback pour trames hex ou autres
            quint32 idHex = convertirCodeHexEnDecimal(line);
            if (idHex > 0) {
                bool inscrit = verifierIDDansBase(idHex);
                qDebug() << "ID (hex→dec) =" << idHex << (inscrit ? "→ inscrit" : "→ n'est pas inscrit");
                emit fingerprintResult(inscrit ? QStringLiteral("inscrit") : QStringLiteral("n'est pas inscrit"));
            }
        }
    }
}

quint32 Empriente::convertirCodeHexEnDecimal(const QByteArray &codeHex)
{
    QByteArray p = codeHex.trimmed();
    QByteArray out;
    for (char c : p) {
        if (c == ' ' || c == '\n' || c == '\r' || c == '\t') continue;
        out.append(c);
    }
    for (char c : out) {
        if (!QChar(c).isDigit() && !((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) {
            return 0;
        }
    }
    bool ok = false;
    quint32 val = out.toUInt(&ok, 16);
    if (!ok) return 0;
    return val;
}

bool Empriente::verifierIDDansBase(quint32 idEmpreinte)
{
    QSqlQuery query;
    query.prepare("SELECT ID_EMPREINTE FROM APPRENANTS WHERE ID_EMPREINTE = :id");
    query.bindValue(":id", idEmpreinte);
    if (!query.exec()) {
        m_lastError = query.lastError().text();
        return false;
    }
    if (query.next()) return true;
    return false;
}
