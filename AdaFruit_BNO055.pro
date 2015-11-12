#-------------------------------------------------
#
# Project created by QtCreator 2015-11-12T21:33:02
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AdaFruit_BNO055
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    adafruit_uart.h

FORMS    += mainwindow.ui
