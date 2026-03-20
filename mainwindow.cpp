#include "mainwindow.h"
#include <QLabel>
#include "serialmanager.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(50, 50, 450, 300);
    labelSerialText = new QLabel("Text from serial", this);
    labelSerialText->setGeometry(50, 50, 100, 50);

    SerialManager *arduino1 = new SerialManager(this);
    connect(arduino1, &SerialManager::messageReceived, labelSerialText, &QLabel::setText);
}

MainWindow::~MainWindow()
{
}



