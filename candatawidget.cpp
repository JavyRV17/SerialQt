#include "candatawidget.h"

candatawidget::candatawidget(QWidget *parent) : QWidget(parent)
{
    QString temp[] = {
        "VehicleSpeed: ",
        "Engine RPM: ",
        "Engine Status: ",
        "Gear Status: ",
        "Fuel Percentage: ",
        "Coolant Temp: ",
        "Battery Voltage: "
    };

    for (int i = 0; i < 7; ++i)
    {
        QLabel* label = new QLabel(this);
        mainlayout->addWidget(label);
        label->setText(temp[i]);
    }
}
