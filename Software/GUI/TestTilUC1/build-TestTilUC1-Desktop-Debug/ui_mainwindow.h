/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *SPITestBut;
    QPushButton *I2CTestBut;
    QPushButton *WiiTestBut;
    QTextBrowser *systemText;
    QPushButton *ExitBut;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 272);
        MainWindow->setMouseTracking(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        SPITestBut = new QPushButton(centralWidget);
        SPITestBut->setObjectName(QString::fromUtf8("SPITestBut"));
        SPITestBut->setGeometry(QRect(10, 10, 80, 31));
        I2CTestBut = new QPushButton(centralWidget);
        I2CTestBut->setObjectName(QString::fromUtf8("I2CTestBut"));
        I2CTestBut->setGeometry(QRect(10, 60, 80, 31));
        WiiTestBut = new QPushButton(centralWidget);
        WiiTestBut->setObjectName(QString::fromUtf8("WiiTestBut"));
        WiiTestBut->setGeometry(QRect(10, 110, 80, 31));
        systemText = new QTextBrowser(centralWidget);
        systemText->setObjectName(QString::fromUtf8("systemText"));
        systemText->setGeometry(QRect(100, 10, 371, 201));
        ExitBut = new QPushButton(centralWidget);
        ExitBut->setObjectName(QString::fromUtf8("ExitBut"));
        ExitBut->setGeometry(QRect(10, 190, 80, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        MainWindow->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "System Tester", 0, QApplication::UnicodeUTF8));
        SPITestBut->setText(QApplication::translate("MainWindow", "Test SPI", 0, QApplication::UnicodeUTF8));
        I2CTestBut->setText(QApplication::translate("MainWindow", "Test I2C", 0, QApplication::UnicodeUTF8));
        WiiTestBut->setText(QApplication::translate("MainWindow", "Test Wii", 0, QApplication::UnicodeUTF8));
        ExitBut->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
