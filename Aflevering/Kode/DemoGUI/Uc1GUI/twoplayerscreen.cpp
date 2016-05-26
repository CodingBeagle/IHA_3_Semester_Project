#include "twoplayerscreen.h"
#include "ui_twoplayerscreen.h"

twoPlayerScreen::twoPlayerScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::twoPlayerScreen)
{
    ui->setupUi(this);
}

twoPlayerScreen::~twoPlayerScreen()
{
    delete ui;
}

void twoPlayerScreen::setTestScores()
{
    ui->playerOneTwoScore->append("# Points in # Attempts");
    ui->playerTwoTwoScore->append("# Points in # Attempts");
    ui->playerOneTwoScore->append("1 Points in 2 Attempts");
    ui->playerTwoTwoScore->append("2 Points in 2 Attempts");
    ui->playerOneTwoScore->append("3 Points in 5 Attempts");
    ui->playerTwoTwoScore->append("4 Points in 5 Attempts");
}


void twoPlayerScreen::on_twoExitBut_clicked()
{
    QWidget::close();
}
