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
    ui->systemText->append("Starting System Test...");
    delay(1000);

    ui->systemText->append("Starting SPI Test...");
    delay(500);

    bool spiTestResult = systemTestGun.SPITest();

    if (spiTestResult == true)
    {
        ui->systemText->append("SPI Test Succeeded!");
    }
    else
    {
        ui->systemText->append("SPI Test Failed!");
        return;
    }

    ui->systemText->append("Starting I2C Test...");
    delay(500);

    bool i2cTestResult = systemTestGun.I2CTest();

    if (i2cTestResult == true)
    {
        ui->systemText->append("I2C Test Succeeded!");
    }
    else
    {
        ui->systemText->append("I2C Test Failed!");
        return;
    }

    ui->systemText->append("Press the 'Z' button on the Nunchuck within 5 seconds...");
    delay(500);

    bool wiiNunchuckTest = systemTestGun.NunchuckTest();

    if (wiiNunchuckTest == true)
    {
        ui->systemText->append("Wii-Nunchuck Test Succeeded!");
    }
    else
    {
        ui->systemText->append("Wii-Nunchuck Test Failed!");
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
