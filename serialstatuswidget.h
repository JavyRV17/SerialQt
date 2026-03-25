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

    void setLabelSerialText(const QString &text);

private:
    QLabel *labelSerialText;
    QFormLayout *serialTextLayout;
};

#endif // SERIALSTATUSWIDGET_H
