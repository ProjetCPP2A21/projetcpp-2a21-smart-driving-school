#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QSerialPort>
#include <QtSql>  // لازم باش نستعمل QSqlDatabase/QSqlQuery

class Test : public QObject
{
    Q_OBJECT

public:
    explicit Test(QObject *parent = nullptr);
    ~Test();
    void envoyerAuArduino(const QByteArray &msg);

private slots:
    void lireDonneesArduino();

private:
    QSerialPort *arduino;

    // Nouvelle fonction pour vérifier l'empreinte dans la base
    int verifierEmpreinte(const QString &id);
};

#endif // TEST_H
