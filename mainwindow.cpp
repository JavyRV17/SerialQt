#include "mainwindow.h"
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(50, 50, 450, 300);

    startUI();
    startSerialComm();
    startQtConnections();

}

void MainWindow::startUI()
{
    central = new QWidget(this);
    mainlayout = new QVBoxLayout(this);

    statusWidget = new SerialStatusWidget(this);
    mainlayout->addWidget(statusWidget);
    mainlayout->setAlignment(Qt::AlignLeft);

    central->setLayout(mainlayout);
    setCentralWidget(central);
}

void MainWindow::startSerialComm()
{
    arduino1 = new SerialManager("COM4", 9600, this);
}

void MainWindow::startQtConnections()
{
    connect(arduino1, &SerialManager::messageReceived, statusWidget, &SerialStatusWidget::setLabelSerialText);
}

MainWindow::~MainWindow()
{
}




