#ifndef CANDATATYPES_H
#define CANDATATYPES_H

typedef struct  {
    unsigned int id;
    int length;
    unsigned char data[8];
} CanFrame;

typedef struct {
    int vehicleSpeed;
    int engineRPM;
    int egineStatus;
    int gearStatus;
    int fuelPercentage;
    int coolantTemp;
    int batteryVoltage;
} EngineData;


#endif // CANDATATYPES_H
