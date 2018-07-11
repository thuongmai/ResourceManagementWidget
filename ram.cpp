#include "ram.h"

Ram::Ram(QWidget *parent) : QWidget(parent)
{
    uram = 0;
    usedRam = 0;
    totalRam = 0;
    freeRam = 0;
}

void Ram::updateRam()
{
    sysinfo(&si);
    uram = ((si.totalram / megabyte) - (si.freeram / megabyte));

    usedRam = uram * si.mem_unit;
    totalRam = si.totalram/megabyte;
    freeRam = si.freeram/megabyte;
    ramUsage = (uram/totalRam) * 100;
    buffered = si.bufferram/megabyte;
    totalHighRam = si.totalhigh/megabyte;
}

double Ram::getTotalRam()
{
    return ceil(totalRam/1024);
}

double Ram::getFreeRam()
{
    return freeRam;
}

double Ram::getUsedRam()
{
    return usedRam;
}

double Ram::getRamUsage()
{
    return ramUsage;
}

double Ram::getBufferedRam()
{
    return buffered;
}

double Ram::getTotalHighRam()
{
    return totalHighRam;
}
