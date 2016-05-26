#include "gamechoice.h"
#include "ui_gamechoice.h"
#include "oneplayerscreen.h"
#include "twoplayerscreen.h"

gameChoice::gameChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameChoice)
{
    ui->setupUi(this);
}

gameChoice::~gameChoice()
{
    delete ui;
}

void gameChoice::on_choiceOne_clicked()
{
    onePlayerScreen onePlay;
    onePlay.setTestScores();
    onePlay.setModal(true);
    onePlay.exec();

}

void gameChoice::on_choiceTwo_clicked()
{
    twoPlayerScreen twoPlay;
    twoPlay.setTestScores();
    twoPlay.setModal(true);
    twoPlay.exec();

}

void gameChoice::on_choiceExitBut_clicked()
{
    QWidget::close();
}
