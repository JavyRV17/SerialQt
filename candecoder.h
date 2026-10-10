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

    CanSignalProperties engineDataSignalsProperties[10] = {
        {0, 1, 0, 1, 0, "kmh", &vehicleStatus.vehicleSpeed},
        {0, 1, 0, 1, 0, "rpm", &vehicleStatus.engineRPM},
        {0, 1, 0, 1, 0, "bool", &vehicleStatus.egineStatus},
        {0, 1, 0, 1, 0, "Direction", &vehicleStatus.gearStatus},
        {0, 1, 0, 1, 0, "Percent", &vehicleStatus.fuelPercentage},
        {0, 1, 0, 1, 0, "C", &vehicleStatus.coolantTemp},
        {0, 1, 0, 1, 0, "V", &vehicleStatus.batteryVoltage},
    };

    //    void setSignalsProperties(CanSignalProperties *, int);

public slots:
    void decodeVehicleStatus(CanFrame &canData);

signals:
    void canPayloadAbstracted(EngineData &);

};

#endif // CANDECODER_H
