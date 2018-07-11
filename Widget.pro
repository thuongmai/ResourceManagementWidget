#-------------------------------------------------
#
# Project created by QtCreator 2017-03-11T18:54:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Widget
TEMPLATE = app


SOURCES += main.cpp\
        widgetControl.cpp \
    clock.cpp \
    systemstats.cpp \
    ram.cpp \
    cpu.cpp

HEADERS  += widgetControl.h \
    clock.h \
    systemstats.h \
    ram.h \
    cpu.h

FORMS    += widgetUI.ui

RESOURCES +=
