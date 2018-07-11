#include "clock.h"

Clock::Clock(QWidget *parent) : QLCDNumber(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    this->setPalette(Qt::yellow);
    showTime();
}

Clock::~Clock()
{
    delete timer;
}

void Clock::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    display(text);
}

