/********************************************************************************
** Form generated from reading UI file 'sourcewindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOURCEWINDOW_H
#define UI_SOURCEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SourceWindow
{
public:
    QWidget *centralWidget;
    QPushButton *scoreBut;
    QPushButton *exitBut;
    QPushButton *testBut;
    QPushButton *startBut;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SourceWindow)
    {
        if (SourceWindow->objectName().isEmpty())
            SourceWindow->setObjectName(QString::fromUtf8("SourceWindow"));
        SourceWindow->resize(480, 272);
        SourceWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(SourceWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        scoreBut = new QPushButton(centralWidget);
        scoreBut->setObjectName(QString::fromUtf8("scoreBut"));
        scoreBut->setGeometry(QRect(10, 110, 91, 91));
        exitBut = new QPushButton(centralWidget);
        exitBut->setObjectName(QString::fromUtf8("exitBut"));
        exitBut->setGeometry(QRect(370, 110, 91, 91));
        exitBut->setStyleSheet(QString::fromUtf8(""));
        testBut = new QPushButton(centralWidget);
        testBut->setObjectName(QString::fromUtf8("testBut"));
        testBut->setGeometry(QRect(370, 10, 91, 91));
        startBut = new QPushButton(centralWidget);
        startBut->setObjectName(QString::fromUtf8("startBut"));
        startBut->setGeometry(QRect(10, 10, 91, 91));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 481, 211));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/Pictures/Goofybackground.jpeg);"));
        SourceWindow->setCentralWidget(centralWidget);
        graphicsView->raise();
        scoreBut->raise();
        exitBut->raise();
        testBut->raise();
        startBut->raise();
        menuBar = new QMenuBar(SourceWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 20));
        SourceWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SourceWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SourceWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SourceWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SourceWindow->setStatusBar(statusBar);

        retranslateUi(SourceWindow);

        QMetaObject::connectSlotsByName(SourceWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SourceWindow)
    {
        SourceWindow->setWindowTitle(QApplication::translate("SourceWindow", "Goofy Candygun", 0, QApplication::UnicodeUTF8));
        scoreBut->setText(QApplication::translate("SourceWindow", "Highscore", 0, QApplication::UnicodeUTF8));
        exitBut->setText(QApplication::translate("SourceWindow", "Quit", 0, QApplication::UnicodeUTF8));
        testBut->setText(QApplication::translate("SourceWindow", "Start Test", 0, QApplication::UnicodeUTF8));
        startBut->setText(QApplication::translate("SourceWindow", "Start Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SourceWindow: public Ui_SourceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOURCEWINDOW_H
