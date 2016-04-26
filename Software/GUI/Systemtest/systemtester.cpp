#include "systemtester.h"
#include "ui_systemtester.h"
#include <QTime>
#include "CandyGun.hpp"
#include "ICandyGun.hpp"
#include "SimulCandyGun.hpp"


//Delay function
void delay( int mSecsToWait )
{
    //Adds the selected amount of msecs to the current systemclock into waittime
    QTime waitTime = QTime::currentTime().addMSecs( mSecsToWait );
    //While the systemclock is less than the waittime, the loop is processing, allowing the gui to update
    //which would've failed with sleep();
    while( QTime::currentTime() < waitTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}



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

    delay(1000);
    //Starts SPI-test
    testGun.SPITest();
    ui->systemText->append("Starting SPI Test");
    delay(1000);
    //Evaluates result of test
    if(testGun.SPITest()==1)
    {
        ui->systemText->append("SPI Test Successful");
    }
    if(testGun.SPITest()==0)
    {
        ui->systemText->append("SPI Test Unsuccessful");
        return;
    }

    //Starts I2C-test
    testGun.I2CTest();
    ui->systemText->append("Starting I2C Test");
    delay(2000);
    //Evaluates result of test
    if(testGun.I2CTest()==1)
    {
        ui->systemText->append("I2C Test Successful");
    }
    if(testGun.I2CTest()==0)
    {
        ui->systemText->append("I2C Test Unsuccessful");
        return;
    }
    //Starts Nunchuck-test
    testGun.NunchuckTest();
    ui->systemText->append("Starting Nunchuck Test");
    ui->systemText->append("Please press the Z button within 6 seconds");
    delay(6000);
    //Evaluates result of test
    if(testGun.NunchuckTest()==1)
    {
        ui->systemText->append("Nunchuck Test Successful");
        sleep(1);
        ui->systemText->append("System test successful, system is ready for use");
    }
    if(testGun.NunchuckTest()==0)
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
