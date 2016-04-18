#-------------------------------------------------
#
# Project created by QtCreator 2016-03-22T15:45:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestTilUC1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    SimulCandyGun.cpp \
    realCandyGun.cpp

HEADERS  += mainwindow.h \
    secondwindow.h \
    form.h \
    SimulCandyGun.hpp \
    ICandyGun.hpp \
    realCandyGun.hpp

FORMS    += mainwindow.ui
