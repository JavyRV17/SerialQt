#include "serialstatuswidget.h"
#include <QLabel>
#include <QFormLayout>

SerialStatusWidget::SerialStatusWidget(QWidget *parent) : QWidget(parent)
{
    serialTextLayout = new QFormLayout(this);
    labelSerialText = new QLabel();
    statusIndicator = new QLabel;
    engineStatusCanData = new QLabel();

    statusIndicator->setFixedSize(15, 15);
    statusIndicator->setStyleSheet("background-color: red; border-radius: 7px;");

    serialTextLayout->addRow("Status: ", statusIndicator);
    serialTextLayout->setAlignment(statusIndicator, Qt::AlignLeft);

    serialTextLayout->addRow("Data Received: ", labelSerialText);
    serialTextLayout->addRow("Engine Status CAN frame data", engineStatusCanData);

    //Make visible the layout of the widget itself
    setLayout(serialTextLayout);
}

void SerialStatusWidget::setLabelSerialText(const QByteArray &text)
{
    //    QString payload = text.left(1) + "   " + text.mid(1);
    QByteArray readableText = text.toHex().toUpper();
    QString payload;

    for (int i = 0; i < readableText.length(); i += 2)
    {
        if (i == 2)
            payload += "  ";

        payload += readableText.mid(i, 2);
        payload += " ";
    }

    labelSerialText->setText(payload);
}

void SerialStatusWidget::setStatusIndicator(bool arduinoState)
{
    QString color = arduinoState ? "green" : "red";

    statusIndicator->setStyleSheet(QString("background-color: %1; border-radius: 7px;").arg(color));
}

void SerialStatusWidget::setEngineStatusCanData(const EngineData &payload)
{
    engineStatusCanData->setText("Vehicle speed: " + QString::number(payload.vehicleSpeed));
}

SerialStatusWidget::~SerialStatusWidget()
{

}
