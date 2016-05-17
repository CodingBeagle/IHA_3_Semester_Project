/********************************************************************************
** Form generated from reading UI file 'gamechoice.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMECHOICE_H
#define UI_GAMECHOICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gameChoice
{
public:
    QPushButton *choiceOne;
    QPushButton *choiceTwo;
    QPushButton *choiceExitBut;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;

    void setupUi(QDialog *gameChoice)
    {
        if (gameChoice->objectName().isEmpty())
            gameChoice->setObjectName(QString::fromUtf8("gameChoice"));
        gameChoice->resize(480, 272);
        gameChoice->setMaximumSize(QSize(480, 272));
        choiceOne = new QPushButton(gameChoice);
        choiceOne->setObjectName(QString::fromUtf8("choiceOne"));
        choiceOne->setGeometry(QRect(10, 10, 101, 91));
        choiceTwo = new QPushButton(gameChoice);
        choiceTwo->setObjectName(QString::fromUtf8("choiceTwo"));
        choiceTwo->setGeometry(QRect(10, 150, 101, 91));
        choiceExitBut = new QPushButton(gameChoice);
        choiceExitBut->setObjectName(QString::fromUtf8("choiceExitBut"));
        choiceExitBut->setGeometry(QRect(10, 100, 101, 51));
        graphicsView = new QGraphicsView(gameChoice);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(120, 10, 351, 111));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/SinglePlayerGoofy.png);"));
        graphicsView_2 = new QGraphicsView(gameChoice);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(120, 130, 351, 111));
        graphicsView_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/TwoGunGoofy.png);"));

        retranslateUi(gameChoice);

        QMetaObject::connectSlotsByName(gameChoice);
    } // setupUi

    void retranslateUi(QDialog *gameChoice)
    {
        gameChoice->setWindowTitle(QApplication::translate("gameChoice", "Select Mode", 0, QApplication::UnicodeUTF8));
        choiceOne->setText(QApplication::translate("gameChoice", "Single Player", 0, QApplication::UnicodeUTF8));
        choiceTwo->setText(QApplication::translate("gameChoice", "Party Mode", 0, QApplication::UnicodeUTF8));
        choiceExitBut->setText(QApplication::translate("gameChoice", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class gameChoice: public Ui_gameChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMECHOICE_H
