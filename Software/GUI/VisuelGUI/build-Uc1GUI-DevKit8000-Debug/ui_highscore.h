/********************************************************************************
** Form generated from reading UI file 'highscore.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHSCORE_H
#define UI_HIGHSCORE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Highscore
{
public:
    QPushButton *setHiBut;
    QPushButton *clearHiBut;
    QPushButton *exitHiBut;
    QTextBrowser *textHiScore;

    void setupUi(QDialog *Highscore)
    {
        if (Highscore->objectName().isEmpty())
            Highscore->setObjectName(QString::fromUtf8("Highscore"));
        Highscore->resize(480, 272);
        Highscore->setMaximumSize(QSize(480, 272));
        setHiBut = new QPushButton(Highscore);
        setHiBut->setObjectName(QString::fromUtf8("setHiBut"));
        setHiBut->setGeometry(QRect(20, 10, 121, 71));
        clearHiBut = new QPushButton(Highscore);
        clearHiBut->setObjectName(QString::fromUtf8("clearHiBut"));
        clearHiBut->setGeometry(QRect(20, 90, 121, 71));
        exitHiBut = new QPushButton(Highscore);
        exitHiBut->setObjectName(QString::fromUtf8("exitHiBut"));
        exitHiBut->setGeometry(QRect(20, 170, 121, 71));
        textHiScore = new QTextBrowser(Highscore);
        textHiScore->setObjectName(QString::fromUtf8("textHiScore"));
        textHiScore->setGeometry(QRect(150, 10, 321, 231));

        retranslateUi(Highscore);

        QMetaObject::connectSlotsByName(Highscore);
    } // setupUi

    void retranslateUi(QDialog *Highscore)
    {
        Highscore->setWindowTitle(QApplication::translate("Highscore", "Leaderboard", 0, QApplication::UnicodeUTF8));
        setHiBut->setText(QApplication::translate("Highscore", "Set Test Scores", 0, QApplication::UnicodeUTF8));
        clearHiBut->setText(QApplication::translate("Highscore", "Clear Test Scores", 0, QApplication::UnicodeUTF8));
        exitHiBut->setText(QApplication::translate("Highscore", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Highscore: public Ui_Highscore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCORE_H
