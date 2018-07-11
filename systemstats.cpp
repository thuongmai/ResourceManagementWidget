#include "systemstats.h"

SystemStats::SystemStats(QWidget *parent) : QWidget(parent)
{
    cpu = new Cpu(this);
    ram = new Ram(this);
    timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

void SystemStats::update()
{
    cpu->updateCpu();
    ram->updateRam();
}

string SystemStats::getModelName()
{
    string line;
    ifstream finfo("/proc/cpuinfo");
    while (getline(finfo, line))
    {
        stringstream str(line);
        string itype;
        string info;
        if (getline(str,itype,':') && getline(str,info) && itype.substr(0, 10) == "model name")
            return info;
    }
    return "NA";
}

int SystemStats::getBatteryLevel()
{
    FILE *fp;
    int batteryLevel;
    fp = fopen("/sys/class/power_supply/BAT0/capacity", "r");
    if (fp == NULL)
    {
        perror ("Error");
    }
    fscanf(fp, "%d", &batteryLevel);
    fclose(fp);
    return batteryLevel;
}

string SystemStats::getBatteryStatus()
{
    FILE *fp;
    char status;
    fp = fopen("/sys/class/power_supply/BAT0/status", "r");
    if (fp == NULL)
    {
        perror ("Error");
    }
    status = fgetc(fp);
    fclose(fp);
    if (status == 'C') //Charging
        return "(Charging)";
    else if (status == 'D') //discharging
        return "(Discharging)";
    else if (status == 'F') //full
        return "(Full Charged)";
    else
        return "(NA)";
}
