#ifndef CANPARSER_H
#define CANPARSER_H

#include <QObject>

#include "canDataTypes.h"



class CanParser : public QObject
{
    Q_OBJECT
public:
    CanParser(QObject *parent = nullptr);

private:
    QByteArray rawFrame;

public slots:
    void processSerialMessage(const QByteArray &rawFrame);

signals:
    void canSignalConstructed(CanFrame &_frame);


};

#endif // CANPARSER_H
