#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T08:19:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Systemtest
TEMPLATE = app


SOURCES += main.cpp\
        systemtester.cpp \
    CandyGun.cpp

HEADERS  += systemtester.h \
    CandyGun.hpp

FORMS    += systemtester.ui

DISTFILES +=

RESOURCES += \
    background.qrc
