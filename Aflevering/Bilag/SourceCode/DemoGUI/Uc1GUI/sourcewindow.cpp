#include "sourcewindow.h"
#include "ui_sourcewindow.h"
#include "highscore.h"
#include "systemtester.h"
#include "gamechoice.h"
#include "systemtester.h"


SourceWindow::SourceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SourceWindow)
{
    ui->setupUi(this);
}

SourceWindow::~SourceWindow()
{
    delete ui;
}


void SourceWindow::on_startBut_clicked()
{
    gameChoice started;
    started.setModal(true);
    started.exec();
}

void SourceWindow::on_testBut_clicked()
{
    systemtester systemTest;
    systemTest.setModal(true);
    systemTest.exec();
}

void SourceWindow::on_scoreBut_clicked()
{
    Highscore hiscore;
    hiscore.setModal(true);
    hiscore.exec();
}

void SourceWindow::on_exitBut_clicked()
{
    QWidget::close();
}
