#include "oneplayerscreen.h"
#include "ui_oneplayerscreen.h"

onePlayerScreen::onePlayerScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::onePlayerScreen)
{
    ui->setupUi(this);
}

onePlayerScreen::~onePlayerScreen()
{
    delete ui;
}

void onePlayerScreen::setTestScores()
{
    ui->playerScore->append("# Points in # Attempts");
    ui->playerScore->append("1 Points in 3 Attempts");
    ui->playerScore->append("2 Points in 5 Attempts");
}

void onePlayerScreen::on_playerExitBut_clicked()
{
    QWidget::close();
}
