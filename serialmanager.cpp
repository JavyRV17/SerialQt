#include "serialmanager.h"
#include <QDebug>
#include <QString>

SerialManager::SerialManager(const QString & _usbPortName, const int baudRate, QObject *parent) : QObject(parent)
{
    serialDevice = new QSerialPort(this);

    usbPortName = new QString();
    setUsbPortName(_usbPortName);

    serialDevice->setPortName(*usbPortName);
    serialDevice->setBaudRate(baudRate);

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

void SerialManager::setUsbPortName(const QString & _usbPortName)
{
    *usbPortName = _usbPortName;
}

void SerialManager::incomingMessage()
{
    bufferText = serialDevice->readAll();
    qDebug() << bufferText << Qt::endl;

    //Connected to widget serialstatuswidget to set new value from serial
    emit messageReceived(bufferText);
}

void SerialManager::startSerialConnection()
{
    if(serialDevice->open(QIODevice::ReadWrite)) {
        qDebug() << *usbPortName << "ready to transfer\n";
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

