#include "arduino.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

Arduino::Arduino(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
    serial->setPortName("COM5");
    serial->setBaudRate(QSerialPort::Baud9600);

    if(!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Impossible d'ouvrir le port série";
        return;
    }

    QObject::connect(serial, &QSerialPort::readyRead, [this]() {
        QByteArray data = serial->readAll();
        QString uid = QString::fromUtf8(data).trimmed();
        qDebug() << "UID reçu:" << uid;

        if(uid == "123456") {
            qDebug() << "Accès autorisé !";
        } else {
            qDebug() << "Accès refusé !";
        }
    });
}
