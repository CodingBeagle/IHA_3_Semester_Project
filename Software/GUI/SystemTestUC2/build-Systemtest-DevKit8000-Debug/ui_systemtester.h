/********************************************************************************
** Form generated from reading UI file 'systemtester.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMTESTER_H
#define UI_SYSTEMTESTER_H

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

class Ui_Systemtester
{
public:
    QWidget *centralWidget;
    QPushButton *activateBut;
    QTextBrowser *systemText;
    QPushButton *clearBut;
    QPushButton *exitBut;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Systemtester)
    {
        if (Systemtester->objectName().isEmpty())
            Systemtester->setObjectName(QString::fromUtf8("Systemtester"));
        Systemtester->setEnabled(true);
        Systemtester->resize(480, 272);
        Systemtester->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(Systemtester);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setAutoFillBackground(false);
        activateBut = new QPushButton(centralWidget);
        activateBut->setObjectName(QString::fromUtf8("activateBut"));
        activateBut->setGeometry(QRect(10, 10, 91, 111));
        systemText = new QTextBrowser(centralWidget);
        systemText->setObjectName(QString::fromUtf8("systemText"));
        systemText->setGeometry(QRect(110, 10, 351, 191));
        clearBut = new QPushButton(centralWidget);
        clearBut->setObjectName(QString::fromUtf8("clearBut"));
        clearBut->setGeometry(QRect(10, 130, 91, 31));
        exitBut = new QPushButton(centralWidget);
        exitBut->setObjectName(QString::fromUtf8("exitBut"));
        exitBut->setGeometry(QRect(10, 170, 91, 31));
        Systemtester->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Systemtester);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 20));
        Systemtester->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Systemtester);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Systemtester->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Systemtester);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Systemtester->setStatusBar(statusBar);
        toolBar = new QToolBar(Systemtester);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Systemtester->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(Systemtester);

        QMetaObject::connectSlotsByName(Systemtester);
    } // setupUi

    void retranslateUi(QMainWindow *Systemtester)
    {
        Systemtester->setWindowTitle(QApplication::translate("Systemtester", "System Tester", 0, QApplication::UnicodeUTF8));
        activateBut->setText(QApplication::translate("Systemtester", "Start Test", 0, QApplication::UnicodeUTF8));
        clearBut->setText(QApplication::translate("Systemtester", "Clear", 0, QApplication::UnicodeUTF8));
        exitBut->setText(QApplication::translate("Systemtester", "Exit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("Systemtester", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Systemtester: public Ui_Systemtester {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMTESTER_H
