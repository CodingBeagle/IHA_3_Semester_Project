#include "highscore.h"
#include "ui_highscore.h"


Highscore::Highscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Highscore)
{
    ui->setupUi(this);
}

Highscore::~Highscore()
{
    delete ui;
}

void Highscore::on_setHiBut_clicked()
{
    ui->textHiScore->append("PlayerName: Score");
    ui->textHiScore->append("PlayerName: Score");
    ui->textHiScore->append("PlayerName: Score");
}

void Highscore::on_clearHiBut_clicked()
{
    ui->textHiScore->append("This will clear Highscore files");
    ui->textHiScore->clear();
}

void Highscore::on_exitHiBut_clicked()
{
    QWidget::close();
}
