#include "serialmanager.h"
#include <QDebug>

SerialManager::SerialManager(QObject *parent) : QObject(parent)
{
    serialDevice = new QSerialPort(this);
    serialDevice->setPortName("COM4");
    serialDevice->setBaudRate(9600);

    serialDeviceReseaarch = new QTimer(this);
    serialDeviceReseaarch->setInterval(500);

    serialDeviceReseaarch->start();

    connect(serialDevice, &QSerialPort::readyRead, this, &SerialManager::incomingMessage);
    connect(serialDeviceReseaarch, &QTimer::timeout, this, &SerialManager::startSerialConnection);
}

QByteArray SerialManager::rxMessage()
{
    return bufferText;
}

void SerialManager::incomingMessage()
{
    bufferText = serialDevice->readAll();
    qDebug() << bufferText << Qt::endl;
    emit messageReceived(bufferText);
}

void SerialManager::startSerialConnection()
{
    if(serialDevice->open(QIODevice::ReadWrite)) {
        qDebug() << "COM4 ready to transfer";
        serialDeviceReseaarch->stop();
    } else {
        qDebug() << "Trying to connect ..." << Qt::endl;
        serialDevice->open(QIODevice::ReadWrite);
        serialDeviceReseaarch->start();
    }
}

SerialManager::~SerialManager()
{

}

