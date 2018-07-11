#ifndef RAM_H
#define RAM_H

#include <QWidget>
#include <linux/kernel.h>
#include <stdio.h>
#include <sys/sysinfo.h>
#include <math.h>

const double megabyte = 1024 * 1024;

class Ram : public QWidget
{
    Q_OBJECT
public:
    explicit Ram(QWidget *parent = 0);

    double getUsedRam();
    double getTotalRam();
    double getFreeRam();
    double getRamUsage();
    double getBufferedRam();
    double getTotalHighRam();
    void updateRam();
private:
    double uram;
    double usedRam;
    double totalRam;
    double freeRam;
    float  ramUsage;
    double buffered;
    double totalHighRam;
    struct sysinfo si;
};

#endif // RAM_H
