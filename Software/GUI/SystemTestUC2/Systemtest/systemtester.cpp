#include "systemtester.h"
#include "ui_systemtester.h"
#include <QTime>
#include "realCandyGun.hpp"
#include "ICandyGun.hpp"
#include "SimulCandyGun.hpp"

//Delay function
void delay( int mSecsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( mSecsToWait );//Can be changed to .addNSecs or .addSecs
    //Adds milliseconds to currentTime which is derived from the system clock and assigns it to dieTime
    while( QTime::currentTime() < dieTime )//Suspends the event loop where it's called, while currentTime is lower than dieTime
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

void Systemtester::on_activateBut_clicked()
{
    ui->systemText->append("Starting System test");
    //delay(1000);
    //sleep(1);
    testGun.SPITest();
    ui->systemText->append("Starting SPI Test");
    //delay(1000);
    sleep(1);
    if(testGun.SPITest()==1)
    {
        ui->systemText->append("SPI Test Successful");
    }
    if(testGun.SPITest()==0)
    {
        ui->systemText->append("SPI Test Unsuccessful");
        return;
    }

    testGun.I2CTest();
    ui->systemText->append("Starting I2C Test");
    //delay(2000);
    sleep(2);
    if(testGun.I2CTest()==1)
    {
        ui->systemText->append("I2C Test Successful");
    }
    if(testGun.I2CTest()==0)
    {
        ui->systemText->append("I2C Test Unsuccessful");
        return;
    }

    testGun.NunchuckTest();
    ui->systemText->append("Starting Nunchuck Test");
    ui->systemText->append("Please press the Z button within 6 seconds");
    //delay(6000);
    sleep(6);
    if(testGun.NunchuckTest()==1)
    {
        ui->systemText->append("Nunchuck Test Successful");
        //delay(1000);
        sleep(1);
        ui->systemText->append("System test successful, system is ready for use");
    }
    if(testGun.NunchuckTest()==0)
    {
        ui->systemText->append("Nunchuck Test Unsuccessful");
        return;
    }
}

void Systemtester::on_clearBut_clicked()
{
    ui->systemText->clear();
}

void Systemtester::on_exitBut_clicked()
{
    QWidget::close(); //Closes the widget.
}
