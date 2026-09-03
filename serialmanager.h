#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QTimer>
#include <QString>

class SerialManager : public QObject
{
    Q_OBJECT
public:

    SerialManager(const QString & _usbPortName, const int baudRate, QObject *parent = nullptr);
    ~SerialManager();

    QByteArray rxMessage();
    void setUsbPortName(const QString &);

private:
    QSerialPort *serialDevice;
    QByteArray bufferText;

    QTimer *serialDeviceReseaarch;
    QTimer *serialHeartbeat;

    QString *usbPortName;
    bool state;

//Public slots, since other classes will connect these
public slots:
    void incomingMessage();
    void startSerialConnection();
    void serialHbMissing();

signals:
    void messageReceived(QByteArray);
    void arduinoStateConnectionChanged(bool);
};

#endif // SERIALMANAGER_H
