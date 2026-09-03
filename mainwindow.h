#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QMainWindow>

#include "serialstatuswidget.h"
#include "serialmanager.h"
#include "canparser.h"
#include "candecoder.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //Layout stuff
    QWidget *central;
    QVBoxLayout *mainlayout;

    //Comm
    SerialManager *arduino1;
    CanParser *canMessage;
    CanDecoder *MessageDecoded;

    //Widgets
    SerialStatusWidget *statusWidget;

    void startUI();
    void startSerialComm();
    void startQtConnections();
};
#endif // MAINWINDOW_H
