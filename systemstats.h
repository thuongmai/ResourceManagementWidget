#ifndef SYSTEMSTATS_H
#define SYSTEMSTATS_H

#include <QWidget>
#include <QTimer>
#include <QObject>
#include <QLabel>

#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>

#include "cpu.h"
#include "ram.h"

using namespace std;

class SystemStats : public QWidget
{
    Q_OBJECT
public:
    explicit SystemStats(QWidget *parent = 0);
    Cpu *cpu;
    Ram *ram;
    string getModelName();
    int getBatteryLevel();
    string getBatteryStatus();
public slots:
    void update();
private:
    QTimer *timer;
};

#endif // SYSTEMSTATS_H
