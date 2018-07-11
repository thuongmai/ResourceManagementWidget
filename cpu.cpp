#include "cpu.h"

Cpu::Cpu(QWidget *parent) : QWidget(parent)
{
    percentUsage = 0;
    for (int i = 0; i < MAX_CPU; i++)
        cores[i] = 0;
}


int Cpu::read_fields (FILE *fp, unsigned long long int *fields)
{
    int retval;
    char buffer[BUF_MAX];


    if (!fgets (buffer, BUF_MAX, fp))
    { perror ("Error"); }
    /* line starts with c and a string. This is to handle cpu, cpu[0-9]+ */
    retval = sscanf (buffer, "c%*s %Lu %Lu %Lu %Lu %Lu %Lu %Lu %Lu %Lu %Lu",
                     &fields[0],
            &fields[1],
            &fields[2],
            &fields[3],
            &fields[4],
            &fields[5],
            &fields[6],
            &fields[7],
            &fields[8],
            &fields[9]);
    if (retval == 0)
    { return -1; }
    if (retval < 4) /* Atleast 4 fields is to be read */
    {
        fprintf (stderr, "Error reading /proc/stat cpu field\n");
        return 0;
    }
    return 1;
}

//Get the Cores and CPU Usage
double Cpu::calPercentUsage()
{
    FILE *fp;
    unsigned long long int fields[10], total_tick[MAX_CPU], total_tick_old[MAX_CPU], idle[MAX_CPU], idle_old[MAX_CPU], del_total_tick[MAX_CPU], del_idle[MAX_CPU];
    int i, count, cpus = 0;
    double percent_usage;

    fp = fopen ("/proc/stat", "r");
    if (fp == NULL)
    {
        perror ("Error");
    }

    //Count number of CPU core on the machine
    while (read_fields (fp, fields) != -1)
    {
        for (i=0, total_tick[cpus] = 0; i<10; i++)
        { total_tick[cpus] += fields[i]; }
        idle[cpus] = fields[3]; /* idle ticks index */
        cpus++;
    }

    sleep (1);
    fseek (fp, 0, SEEK_SET);
    fflush (fp);
    for (count = 0; count < cpus; count++)
    {
        total_tick_old[count] = total_tick[count];
        idle_old[count] = idle[count];

        if (!read_fields (fp, fields))
        { return 0; }

        for (i=0, total_tick[count] = 0; i<10; i++)
        { total_tick[count] += fields[i]; }
        idle[count] = fields[3];

        del_total_tick[count] = total_tick[count] - total_tick_old[count];
        del_idle[count] = idle[count] - idle_old[count];

        //percent_usage = ((del_total_tick[count] - del_idle[count]) / (double) del_total_tick[count]) * 100;

        switch (count)
        {
        case 0: percent_usage = ((del_total_tick[count] - del_idle[count]) / (double) del_total_tick[count]) * 100;
            break;
        case 1: cores[0] = ((del_total_tick[count] - del_idle[count]) / (double) del_total_tick[count]) * 100;
            break;

        case 2: cores[1] = ((del_total_tick[count] - del_idle[count]) / (double) del_total_tick[count]) * 100;
            break;

        case 3: cores[2] = ((del_total_tick[count] - del_idle[count]) / (double) del_total_tick[count]) * 100;
            break;
        case 4: cores[3] = ((del_total_tick[count] - del_idle[count]) / (double) del_total_tick[count]) * 100;
            break;
        }
    }

    /* Ctrl + C quit, therefore this will not be reached. We rely on the kernel to close this file */
    fclose (fp);

    return percent_usage;
}


void Cpu::updateCpu()
{
    percentUsage = calPercentUsage();
    /*printf("Total: %3.2lf%%\n", percentUsage);
    printf ("Core0 : %3.2lf%%\n", cores[0]);
    printf ("Core1 : %3.2lf%%\n", cores[1]);
    printf ("Core2 : %3.2lf%%\n", cores[2]);
    printf ("Core3 : %3.2lf%%\n", cores[3]);*/
}

double Cpu::getPercentUsage()
{
    return percentUsage;
}

double* Cpu::getCores()
{
    return cores;
}
