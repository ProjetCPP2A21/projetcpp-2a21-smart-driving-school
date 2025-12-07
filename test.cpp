#include "test.h"
#include <QDebug>

Test::Test(QObject *parent)
    : QObject(parent),
    arduino(new QSerialPort(this))
{
    // --------------------------------
    // Configuration du port série
    // --------------------------------
    arduino->setPortName("COM3");  // ⚠️ changer selon ton port
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    if (arduino->open(QSerialPort::ReadWrite)) {
        qDebug() << "Arduino connecté ✔";
    } else {
        qDebug() << "Erreur : impossible d'ouvrir le port ❌";
    }

    connect(arduino, &QSerialPort::readyRead,
            this, &Test::lireDonneesArduino);
}

Test::~Test()
{
    if (arduino->isOpen())
        arduino->close();
}

void Test::lireDonneesArduino()
{
    QByteArray data = arduino->readAll();
    QString texte = QString::fromUtf8(data).trimmed();

    qDebug() << "Reçu :" << texte;

    if (texte.startsWith("ID:")) {
        QString id = texte.mid(3).trimmed();
        qDebug() << "Empreinte détectée =" << id;

        // Vérifier dans la base
        int result = verifierEmpreinte(id);

        // Envoyer le résultat à Arduino (1 = existe, 0 = n'existe pas)
        if (arduino->isOpen()) {
            arduino->write(result ? "1" : "0");
            qDebug() << "Envoyé à Arduino :" << (result ? "1" : "0");
        }
    }
}

// Fonction qui vérifie l'ID dans la base SQL
int Test::verifierEmpreinte(const QString &id)
{
    QSqlQuery query(QSqlDatabase::database("oracle_connection"));

    query.prepare("SELECT COUNT(*) FROM EMPREINTES WHERE ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        return 0; // si erreur, considérer que l'ID n'existe pas
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        return (count > 0) ? 1 : 0;
    }

    return 0;
}
void Test::envoyerAuArduino(const QByteArray &msg)
{
    if (!arduino->isOpen()) {
        qDebug() << "Port série non ouvert";
        return;
    }
    arduino->write(msg);
    arduino->flush();
    qDebug() << "Envoyé (manuel) au Arduino:" << msg;
}
