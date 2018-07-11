#ifndef CPU_H
#define CPU_H

#include <QWidget>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUF_MAX 1024
#define MAX_CPU 4

class Cpu : public QWidget
{
    Q_OBJECT
public:
    explicit Cpu(QWidget *parent = 0);
    int read_fields(FILE *fp, unsigned long long int *fields);
    double calPercentUsage();
    void updateCpu();

    int getTemp();
    double getPercentUsage();
    double* getCores();
private:
    double percentUsage;
    double cores[MAX_CPU];
};

#endif // CPU_H
