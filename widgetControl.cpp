#include "widgetControl.h"
#include "ui_widgetUI.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QMenuBar>
#include <QMenu>

Widget::Widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Update for every 1000ms (1 sec)
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateUI()));
    timer->start(1000);

    clock = new Clock(this);
    systemStats = new SystemStats(this);

    ui->clockLayout->addWidget(clock);
    ui->processorLb->setText(QString::fromStdString(systemStats->getModelName()));

    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint); //Disable resize (worked on Windows)
    this->setFixedSize(QSize(315, 332)); //Set fixed size to disable resize (worked on Linux)
}

Widget::~Widget()
{
    delete clock;
    delete ui;
    delete systemStats;
    delete timer;
}

//Refresh the UI
void Widget::updateUI()
{
    ui->ramUsagelb->setText("RAM Usage " + QString::number(systemStats->ram->getRamUsage(), 'f', 1) + "%");
    ui->ramTotalLb->setText("Ram installed: " + QString::number(systemStats->ram->getTotalRam(), 'f', 2) + "GB");
    ui->usedRamLb->setText("Used: " + QString::number(systemStats->ram->getUsedRam(), 'f', 1) + "MB");
    ui->freeRamLb->setText("Free: " + QString::number(systemStats->ram->getFreeRam(), 'f', 1) + "MB");
    ui->bufferedRamlb->setText("Buffered: " + QString::number(systemStats->ram->getBufferedRam(), 'f', 1) + "MB");
    ui->highRamlb->setText("Total high RAM: " + QString::number(systemStats->ram->getTotalHighRam(), 'f', 1) + "MB");
    if (systemStats->ram->getRamUsage() > 80)
        ui->ramUsagelb->setStyleSheet("color: rgb(255, 0, 0);");
    else
        ui->ramUsagelb->setStyleSheet("color: rgb(0, 255, 0);");

    ui->cpuUsedLb->setText("CPU Usage " + QString::number(systemStats->cpu->getPercentUsage(), 'f', 0) + "%");
    ui->core0lb->setText("Core 0: " + QString::number(systemStats->cpu->getCores()[0], 'f', 0) + "%");
    ui->core1lb->setText("Core 1: " + QString::number(systemStats->cpu->getCores()[1], 'f', 0) + "%");
    ui->core2lb->setText("Core 2: " + QString::number(systemStats->cpu->getCores()[2], 'f', 0) + "%");
    ui->core3lb->setText("Core 3: " + QString::number(systemStats->cpu->getCores()[3], 'f', 0) + "%");
    if (systemStats->cpu->getPercentUsage() > 80)
        ui->cpuUsedLb->setStyleSheet("color: rgb(255, 0, 0);");
    else
        ui->cpuUsedLb->setStyleSheet("color: rgb(0, 255, 255);");

    ui->batteryLb->setText("Battery: " + QString::number(systemStats->getBatteryLevel(), 'f', 0) + "%" + QString::fromStdString(systemStats->getBatteryStatus()));
}
