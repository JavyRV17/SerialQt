#include "mainwindow.h"
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    startUI();
    startSerialComm();
    startQtConnections();
}

void MainWindow::startUI()
{
    this->setGeometry(50, 50, 450, 300);
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

#ifndef Q_OS_LINUX
    arduino1 = new SerialManager("COM3", 115200, this);
#else 
    arduino1 = new SerialManager("ttyUSB0", 115200, this);
#endif

    canMessage = new CanParser(this);
    MessageDecoded =  new CanDecoder(this);

}

//TODO: One only module with all the QT CONNECTIONS?
void MainWindow::startQtConnections()
{
    connect(arduino1, &SerialManager::messageReceived, statusWidget, &SerialStatusWidget::setLabelSerialText);
    connect(arduino1, &SerialManager::messageReceived, canMessage, &CanParser::processSerialMessage);
    connect(arduino1, &SerialManager::arduinoStateConnectionChanged, statusWidget, &SerialStatusWidget::setStatusIndicator);

    connect(canMessage, &CanParser::canSignalConstructed, MessageDecoded, &CanDecoder::decodeVehicleStatus);
    connect(MessageDecoded, &CanDecoder::canPayloadAbstracted, statusWidget, &SerialStatusWidget::setEngineStatusCanData);
}

MainWindow::~MainWindow()
{
}




