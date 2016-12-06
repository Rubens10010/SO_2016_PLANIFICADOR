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
    proceso.cpp \
    cola.cpp \
    fcfs.cpp \
    misalgoritmos.cpp \
    prioridad1.cpp \
    prioridad2.cpp \
    simulacion.cpp \
    colaprincipal.cpp \
    roundrobin.cpp \
    sjf.cpp \
    strf.cpp

HEADERS  += mainwindow.h \
    proceso.h \
    cola.h \
    fcfs.h \
    misalgoritmos.h \
    prioridad1.h \
    prioridad2.h \
    simulacion.h \
    colaprincipal.h \
    roundrobin.h \
    sjf.h \
    strf.h

FORMS    += mainwindow.ui

CONFIG += c++11
