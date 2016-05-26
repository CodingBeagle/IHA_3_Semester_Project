#-------------------------------------------------
#
# Project created by QtCreator 2016-05-17T09:37:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Uc1GUI
TEMPLATE = app


SOURCES += main.cpp\
        sourcewindow.cpp \
    highscore.cpp \
    CandyGun.cpp \
    gamechoice.cpp \
    oneplayerscreen.cpp \
    twoplayerscreen.cpp \
    systemtester.cpp

HEADERS  += sourcewindow.h \
    highscore.h \
    CandyGun.hpp \
    gamechoice.h \
    oneplayerscreen.h \
    twoplayerscreen.h \
    systemtester.h

FORMS    += sourcewindow.ui \
    highscore.ui \
    gamechoice.ui \
    oneplayerscreen.ui \
    twoplayerscreen.ui \
    systemtester.ui

RESOURCES += \
    pictures.qrc
