#include "serialstatuswidget.h"
#include <QLabel>
#include <QFormLayout>

SerialStatusWidget::SerialStatusWidget(QWidget *parent) : QWidget(parent)
{
    serialTextLayout = new QFormLayout(this);
    labelSerialText = new QLabel();

    serialTextLayout->addRow("Data Received: ", labelSerialText);

    //Make visible the layout of the widget itself
    setLayout(serialTextLayout);
}

void SerialStatusWidget::setLabelSerialText(const QString &text)
{
    labelSerialText->setText(text);
}

SerialStatusWidget::~SerialStatusWidget()
{

}
