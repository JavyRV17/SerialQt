#ifndef SERIALSTATUSWIDGET_H
#define SERIALSTATUSWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QFormLayout>

class SerialStatusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SerialStatusWidget(QWidget *parent = nullptr);
    ~SerialStatusWidget();

public slots:
    void setLabelSerialText(const QString &text);
    void setStatusIndicator(bool);

private:
    QLabel *labelSerialText;
    QFormLayout *serialTextLayout;
    QLabel *statusIndicator;
};

#endif // SERIALSTATUSWIDGET_H
