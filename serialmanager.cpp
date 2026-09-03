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

    serialHeartbeat = new QTimer(this);
    serialHeartbeat->setInterval(3000);
    serialHeartbeat->setSingleShot(true);

    connect(serialDevice, &QSerialPort::readyRead, this, &SerialManager::incomingMessage);

    connect(serialDeviceReseaarch, &QTimer::timeout, this, &SerialManager::startSerialConnection);
    connect(serialHeartbeat, &QTimer::timeout, this, &SerialManager::serialHbMissing);
}

QByteArray SerialManager::rxMessage()
{
    return bufferText;
}

void SerialManager::setUsbPortName(const QString & _usbPortName)
{
    *usbPortName = _usbPortName;
}

//Slot triggered every time QSERIALUSB deliver a message
void SerialManager::incomingMessage()
{
    bufferText += serialDevice->readAll();
    qDebug() << "raw buffer" << bufferText << Qt::endl;
    QByteArray frame;
    int sofIndex;

    if (bufferText.contains(0xAA)) {

        if (bufferText.startsWith(0xAA)) {

            if(bufferText.length() >= 11) {
                frame = bufferText.left(11);
                qDebug() << "data processed" << frame << Qt::endl;
                bufferText.remove(0, 11);
            }
        } else {
            sofIndex = bufferText.indexOf(0xAA);
            bufferText.remove(0, sofIndex);
        }
    }
    //Connected to widget serialstatuswidget to set new value from serial
    //    qDebug() << "After processing" << bufferText << Qt::endl;
    emit messageReceived(frame);

    serialHeartbeat->start();
}

void SerialManager::startSerialConnection()
{
    if(serialDevice->open(QIODevice::ReadWrite)) {
        qDebug() << *usbPortName << "ready to transfer\n";
        serialDeviceReseaarch->stop();
        emit arduinoStateConnectionChanged(true);

    } else {
        qDebug() << "Trying to connect ..." << Qt::endl;
        serialDevice->open(QIODevice::ReadWrite);
        serialDeviceReseaarch->start();
        emit arduinoStateConnectionChanged(false);
    }
}

void SerialManager::serialHbMissing()
{
    qDebug() << "Missing data, info not relaiable" << Qt::endl;
}

SerialManager::~SerialManager()
{

}

