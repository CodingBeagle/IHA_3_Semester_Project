#include "systemtester.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Systemtester w;
    w.show();

    return a.exec();
}
