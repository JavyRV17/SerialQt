#include "serialstatuswidget.h"
#include <QLabel>
#include <QFormLayout>

SerialStatusWidget::SerialStatusWidget(QWidget *parent) : QWidget(parent)
{
    serialTextLayout = new QFormLayout(this);
    labelSerialText = new QLabel();
    statusIndicator = new QLabel;

    statusIndicator->setFixedSize(15, 15);
    statusIndicator->setStyleSheet("background-color: red; border-radius: 7px;");

    serialTextLayout->addRow("Status: ", statusIndicator);
    serialTextLayout->setAlignment(statusIndicator, Qt::AlignLeft);

    serialTextLayout->addRow("Data Received: ", labelSerialText);

    //Make visible the layout of the widget itself
    setLayout(serialTextLayout);
}

void SerialStatusWidget::setLabelSerialText(const QString &text)
{
    labelSerialText->setText(text);
}

void SerialStatusWidget::setStatusIndicator(bool arduinoState)
{
    QString color = arduinoState ? "green" : "red";

    statusIndicator->setStyleSheet(QString("background-color: %1; border-radius: 7px;").arg(color));
}

SerialStatusWidget::~SerialStatusWidget()
{

}
