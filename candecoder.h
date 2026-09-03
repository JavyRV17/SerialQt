#ifndef CANDECODER_H
#define CANDECODER_H

#include <QObject>

#include "canDataTypes.h"

class CanDecoder : public QObject
{
    Q_OBJECT
public:
    CanDecoder(QObject *parent = nullptr);
    EngineData vehicleStatus;

public slots:
    void decodeVehicleStatus(CanFrame &canData);

signals:
    void canPayloadAbstracted(EngineData &);

};

#endif // CANDECODER_H
