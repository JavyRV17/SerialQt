#include "mainwindow.h"
#include <QLabel>
#include "serialmanager.h"
#include "serialstatuswidget.h"
#include <QWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(50, 50, 450, 300);

    QWidget *central = new QWidget(this);
    QVBoxLayout *mainlayout = new QVBoxLayout(this);

    SerialStatusWidget *statusWidget = new SerialStatusWidget(this);
    mainlayout->addWidget(statusWidget);
    mainlayout->setAlignment(Qt::AlignLeft);

    central->setLayout(mainlayout);
    setCentralWidget(central);

    SerialManager *arduino1 = new SerialManager(this);

    //Connections
    connect(arduino1, &SerialManager::messageReceived, statusWidget, &SerialStatusWidget::setLabelSerialText);
}

MainWindow::~MainWindow()
{
}



