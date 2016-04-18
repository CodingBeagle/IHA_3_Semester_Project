#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include "ICandyGun.hpp"
#include "SimulCandyGun.hpp"
#include "realCandyGun.hpp"

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

//Integers for conditions
int sTest,iTest,wTest = 0;

//Constructor for testRunGun
CandyGun testRunGun;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


//Function to indicate the completion of the test UC
//Implemented as a private slot in the MainWindow class, since it accesses the Ui
void MainWindow::fullTest()
{
    if(sTest && iTest && wTest == 1)
    {
      ui->systemText->append("System test gennemfoert, og Systemet er klart"); //Writes to the text window
      sTest = 0;
      iTest = 0;
      wTest = 0;
      delay(5000);//Delay called to enable user to read the system message.
      ui->systemText->clear();//Clears text window
    }
    else
        return;
}
void MainWindow::on_SPITestBut_clicked()
{


 testRunGun.SPITest();
 if(testRunGun.SPITest() == 1)
    {
        ui->systemText->append("SPI Test lykkedes.");
        sTest = 1;
    }
 else
    {
        ui->systemText->append("SPI Test mislykkedes.");
    }
  if(wTest && iTest == 1)
       fullTest();
}




void MainWindow::on_I2CTestBut_clicked()
{
  testRunGun.I2CTest();
  if(testRunGun.I2CTest() == 1)
      {
            ui->systemText->append("I2C Test lykkedes.");
            iTest = 1;
      }
  else
      {
            ui->systemText->append("I2C Test mislykkedes");

      }

  if(sTest && wTest == 1)
        fullTest();
}

void MainWindow::on_WiiTestBut_clicked()
{
  testRunGun.NunchuckTest();
  if(testRunGun.NunchuckTest() == 1)
    {
            ui->systemText->append("Wii Test lykkedes.");
            wTest = 1;
    }
  else
    {
            ui->systemText->append("Wii Test mislykkedes.");

    }

  if(sTest && iTest == 1)
        fullTest();
}


void MainWindow::on_ExitBut_clicked()
{
   QWidget::close(); //Closes the widget.
}

void MainWindow::on_ClearBut_clicked()
{
    ui->systemText->clear();
}
