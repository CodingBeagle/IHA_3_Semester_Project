#include "systemtester.h"
#include "ui_systemtester.h"
#include <QTime>
#include "CandyGun.hpp"




CandyGun testGun;

Systemtester::Systemtester(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Systemtester)
{
    ui->setupUi(this);
}

Systemtester::~Systemtester()
{
    delete ui;
}
//Systems test button
void Systemtester::on_activateBut_clicked()
{
    //Writes to the text window
    ui->systemText->append("Starting System test");

    //Starts SPI-test
    ui->systemText->append("Starting SPI Test");

    //Evaluates result of test
    if(testGun.SPITest()==1)
    {
        ui->systemText->append("SPI Test Successful");
    }
    else
    {
        ui->systemText->append("SPI Test Unsuccessful");
        return;
    }

    //Starts I2C-test
    ui->systemText->append("Starting I2C Test");

    //Evaluates result of test
    if(testGun.I2CTest()==1)
    {
        ui->systemText->append("I2C Test Successful");
    }
    else
    {
        ui->systemText->append("I2C Test Unsuccessful");
        return;
    }
    //Starts Nunchuck-test
    ui->systemText->append("Starting Nunchuck Test");
    ui->systemText->append("Please press the Z button within 6 seconds");

    //Evaluates result of test
    if(testGun.NunchuckTest() == 1)
    {
        ui->systemText->append("Nunchuck Test Successful");
        sleep(1);
        ui->systemText->append("System test successful, system is ready for use");
    }
    else
    {
        ui->systemText->append("Nunchuck Test Unsuccessful");
        return;
    }
}

//Button for clearing text window
void Systemtester::on_clearBut_clicked()
{
    ui->systemText->clear();
}

//Button for closing widget
void Systemtester::on_exitBut_clicked()
{
    QWidget::close();
}
