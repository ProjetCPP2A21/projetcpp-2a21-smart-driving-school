#ifndef EMPRIENCE_H
#define EMPRIENCE_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Empriente : public QObject
{
    Q_OBJECT
public:
    explicit Empriente(QObject *parent = nullptr);
    bool connecterArduino();
    void envoyerCommande(QString cmd);
    static quint32 convertirCodeHexEnDecimal(const QByteArray &codeHex);
    bool verifierIDDansBase(quint32 idEmpreinte);
    QString dernierMessageErreur() const { return m_lastError; }
    QString portActuel() const { return m_port; }

signals:
    void fingerprintResult(QString resultat);

private slots:
    void lireDonnees();
    void lirePort();

private:
    QSerialPort *arduino;
    QString m_lastError;
    QString m_port;
};

#endif // EMPRIENCE_H
