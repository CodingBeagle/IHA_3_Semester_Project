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
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *FindEdit;
    QLineEdit *ReplaceEdit;
    QLineEdit *AppendEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *DesignateEdit;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menuTestGUI;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(724, 376);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 90, 111, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 10, 111, 23));
        FindEdit = new QLineEdit(centralWidget);
        FindEdit->setObjectName(QString::fromUtf8("FindEdit"));
        FindEdit->setGeometry(QRect(10, 60, 151, 23));
        ReplaceEdit = new QLineEdit(centralWidget);
        ReplaceEdit->setObjectName(QString::fromUtf8("ReplaceEdit"));
        ReplaceEdit->setGeometry(QRect(160, 60, 151, 23));
        AppendEdit = new QLineEdit(centralWidget);
        AppendEdit->setObjectName(QString::fromUtf8("AppendEdit"));
        AppendEdit->setGeometry(QRect(10, 120, 301, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 71, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 40, 61, 21));
        DesignateEdit = new QLineEdit(centralWidget);
        DesignateEdit->setObjectName(QString::fromUtf8("DesignateEdit"));
        DesignateEdit->setGeometry(QRect(320, 60, 301, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(320, 10, 80, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 724, 20));
        menuTestGUI = new QMenu(menuBar);
        menuTestGUI->setObjectName(QString::fromUtf8("menuTestGUI"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuTestGUI->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Append", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "FindReplace", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Find", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Replace", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        menuTestGUI->setTitle(QApplication::translate("MainWindow", "TestGUI", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
