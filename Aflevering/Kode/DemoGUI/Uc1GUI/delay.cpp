#include <QTime>
#include <QApplication>
#include "delay.h"

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
