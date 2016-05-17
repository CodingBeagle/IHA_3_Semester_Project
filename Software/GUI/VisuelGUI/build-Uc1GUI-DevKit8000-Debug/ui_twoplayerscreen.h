/********************************************************************************
** Form generated from reading UI file 'twoplayerscreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWOPLAYERSCREEN_H
#define UI_TWOPLAYERSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_twoPlayerScreen
{
public:
    QTextBrowser *playerOneTwoScore;
    QTextBrowser *playerTwoTwoScore;
    QPushButton *twoExitBut;
    QLabel *playerOneTwo;
    QLabel *playerTwoTwo;

    void setupUi(QDialog *twoPlayerScreen)
    {
        if (twoPlayerScreen->objectName().isEmpty())
            twoPlayerScreen->setObjectName(QString::fromUtf8("twoPlayerScreen"));
        twoPlayerScreen->resize(480, 262);
        twoPlayerScreen->setMaximumSize(QSize(480, 272));
        playerOneTwoScore = new QTextBrowser(twoPlayerScreen);
        playerOneTwoScore->setObjectName(QString::fromUtf8("playerOneTwoScore"));
        playerOneTwoScore->setGeometry(QRect(120, 30, 171, 211));
        playerTwoTwoScore = new QTextBrowser(twoPlayerScreen);
        playerTwoTwoScore->setObjectName(QString::fromUtf8("playerTwoTwoScore"));
        playerTwoTwoScore->setGeometry(QRect(300, 30, 171, 211));
        twoExitBut = new QPushButton(twoPlayerScreen);
        twoExitBut->setObjectName(QString::fromUtf8("twoExitBut"));
        twoExitBut->setGeometry(QRect(10, 170, 101, 71));
        playerOneTwo = new QLabel(twoPlayerScreen);
        playerOneTwo->setObjectName(QString::fromUtf8("playerOneTwo"));
        playerOneTwo->setGeometry(QRect(120, 0, 171, 31));
        QFont font;
        font.setPointSize(12);
        playerOneTwo->setFont(font);
        playerTwoTwo = new QLabel(twoPlayerScreen);
        playerTwoTwo->setObjectName(QString::fromUtf8("playerTwoTwo"));
        playerTwoTwo->setGeometry(QRect(300, 0, 171, 31));
        playerTwoTwo->setFont(font);

        retranslateUi(twoPlayerScreen);

        QMetaObject::connectSlotsByName(twoPlayerScreen);
    } // setupUi

    void retranslateUi(QDialog *twoPlayerScreen)
    {
        twoPlayerScreen->setWindowTitle(QApplication::translate("twoPlayerScreen", "Party Mode", 0, QApplication::UnicodeUTF8));
        twoExitBut->setText(QApplication::translate("twoPlayerScreen", "Exit Mode", 0, QApplication::UnicodeUTF8));
        playerOneTwo->setText(QApplication::translate("twoPlayerScreen", "Player One Score:", 0, QApplication::UnicodeUTF8));
        playerTwoTwo->setText(QApplication::translate("twoPlayerScreen", "Player Two Score:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class twoPlayerScreen: public Ui_twoPlayerScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWOPLAYERSCREEN_H
