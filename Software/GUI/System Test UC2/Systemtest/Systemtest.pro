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
    realCandyGun.cpp \
    SimulCandyGun.cpp

HEADERS  += systemtester.h \
    realCandyGun.hpp \
    ICandyGun.hpp \
    SimulCandyGun.hpp

FORMS    += systemtester.ui
