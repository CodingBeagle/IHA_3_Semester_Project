#include "mainwindow.h"
#include <QApplication>
#include "ICandyGun.hpp"
#include "SimulCandyGun.hpp"
#include "realCandyGun.hpp"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
