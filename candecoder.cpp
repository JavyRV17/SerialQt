#include "candecoder.h"

CanDecoder::CanDecoder(QObject *parent) : QObject(parent)
{

}

void CanDecoder::decodeVehicleStatus(CanFrame &canData)
{
    for (int i = 0; i < canData.length; i++) {

        *engineDataSignalsProperties[i].dataPtr =
                //CAN raw value    Scale
                (canData.data[i] * engineDataSignalsProperties[i].scale)
                //Offset
                + engineDataSignalsProperties[i].factor;
    }

    emit canPayloadAbstracted(vehicleStatus);
}


