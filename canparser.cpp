#include "canparser.h"
#include <QDebug>

CanParser::CanParser(QObject *parent) : QObject(parent)
{

}

void CanParser::processSerialMessage(const QByteArray &rawFrame)
{
    CanFrame frame;
    frame.id = (unsigned char)rawFrame[1];
    frame.length = (unsigned char)rawFrame[2];

    for(int i = 0; i < frame.length; i++) {

        frame.data[i] = (unsigned char)rawFrame[i + 3];

        //This line is saying store payload from byte 1, to the vehicleSpeed member of engineCanMessage struct
        //Using its corresponding offset and scale
        //        if(i == 0) {
        //            engineCanMessage.vehicleSpeed = (frame.data[i] * 1) + 0 ;
        //            qDebug() << engineCanMessage.vehicleSpeed << Qt::endl;
        //        }
    }

    for(int i = 0; i < frame.length; i++) {
        qDebug() << frame.data[i] << " ";
    }

    qDebug() << Qt::endl;
    qDebug() << frame.id << Qt::endl;
    qDebug() << frame.length << Qt::endl;

    emit canSignalConstructed(frame);
}
