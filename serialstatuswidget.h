#ifndef SERIALSTATUSWIDGET_H
#define SERIALSTATUSWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QFormLayout>
#include <QVector>

#include "canDataTypes.h"

class SerialStatusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SerialStatusWidget(QWidget *parent = nullptr);
    ~SerialStatusWidget();

public slots:
    void setLabelSerialText(const QByteArray &text);
    void setStatusIndicator(bool);

    //To show vehicle speed
    void setEngineStatusCanData(const EngineData &payload);

private:
    QLabel *labelSerialText;
    QFormLayout *serialTextLayout;
    QLabel *statusIndicator;
    QLabel *engineStatusCanData;
};

#endif // SERIALSTATUSWIDGET_H
