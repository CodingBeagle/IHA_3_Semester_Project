#include "sourcewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SourceWindow w;
    w.show();

    return a.exec();
}
