#ifndef WIDGETCONTROL_H
#define WIDGETCONTROL_H

#include <QWidget>
#include <QMainWindow>
#include "clock.h"
#include "systemstats.h"
#include <QTimer>

#include <QListWidget>
#include <QPoint>
#include <QMenu>
#include <QListWidgetItem>
#include <string.h>

namespace Ui {
class Widget;
}

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void updateUI();
private:
    Ui::Widget *ui;
    Clock *clock;
    SystemStats *systemStats;
    QTimer *timer;
};

#endif // WIDGETCONTROL_H
