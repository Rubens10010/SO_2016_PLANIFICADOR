#-------------------------------------------------
#
# Project created by QtCreator 2016-11-22T19:17:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Scheduler_SO
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    proceso.cpp

HEADERS  += mainwindow.h \
    proceso.h

FORMS    += mainwindow.ui

CONFIG += c++11
