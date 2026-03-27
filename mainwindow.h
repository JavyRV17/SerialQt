#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QMainWindow>

#include "serialstatuswidget.h"
#include "serialmanager.h"

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

    //Widgets
    SerialStatusWidget *statusWidget;

    void startUI();
    void startSerialComm();
    void startQtConnections();
};
#endif // MAINWINDOW_H
