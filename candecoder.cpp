#include "candecoder.h"

CanDecoder::CanDecoder(QObject *parent) : QObject(parent)
{

}

void CanDecoder::decodeVehicleStatus(CanFrame &canData)
{
    for (int i = 0; i < canData.length; i++) {

        //Vehicle speed member from struct
        if (i == 0)
        {                                               //scale  offset
            vehicleStatus.vehicleSpeed = (canData.data[i] * 1) + 0;
        }

        //Engine rpm member from struct
        if(i == 1)
        {                                               //scale  offset
            vehicleStatus.engineRPM = (canData.data[i] * 13.72) + 0;
        }
    }

    emit canPayloadAbstracted(vehicleStatus);
}


