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

//Constructor for test purposes
//SimulCandyGun systemTestGun;

//Constructor for real usage
CandyGun systemTestGun;


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
    delay(1000);
    systemTestGun.SPITest();
    ui->systemText->append("Starting SPI Test");
    delay(1000);
    if(systemTestGun.SPITest()==1)
    {
        ui->systemText->append("SPI Test Successful");
    }
    if(systemTestGun.SPITest()==0)
    {
        ui->systemText->append("SPI Test Unsuccessful");
        return;
    }

    systemTestGun.I2CTest();
    ui->systemText->append("Starting I2C Test");
    delay(2000);
    if(systemTestGun.I2CTest()==1)
    {
        ui->systemText->append("I2C Test Successful");
    }
    if(systemTestGun.I2CTest()==0)
    {
        ui->systemText->append("I2C Test Unsuccessful");
        return;
    }

    systemTestGun.NunchuckTest();
    ui->systemText->append("Starting Nunchuck Test");
    ui->systemText->append("Please press the Z button within 6 seconds");
    delay(6000);
    if(systemTestGun.NunchuckTest()==1)
    {
        ui->systemText->append("Nunchuck Test Successful");
        delay(1000);
        ui->systemText->append("System test successful, system is ready for use");
    }
    if(systemTestGun.NunchuckTest()==0)
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
