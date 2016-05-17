/********************************************************************************
** Form generated from reading UI file 'oneplayerscreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONEPLAYERSCREEN_H
#define UI_ONEPLAYERSCREEN_H

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

class Ui_onePlayerScreen
{
public:
    QTextBrowser *playerScore;
    QLabel *playerLabel;
    QPushButton *playerExitBut;

    void setupUi(QDialog *onePlayerScreen)
    {
        if (onePlayerScreen->objectName().isEmpty())
            onePlayerScreen->setObjectName(QString::fromUtf8("onePlayerScreen"));
        onePlayerScreen->resize(480, 272);
        playerScore = new QTextBrowser(onePlayerScreen);
        playerScore->setObjectName(QString::fromUtf8("playerScore"));
        playerScore->setGeometry(QRect(120, 40, 351, 201));
        playerLabel = new QLabel(onePlayerScreen);
        playerLabel->setObjectName(QString::fromUtf8("playerLabel"));
        playerLabel->setGeometry(QRect(120, 0, 111, 41));
        QFont font;
        font.setPointSize(14);
        playerLabel->setFont(font);
        playerLabel->setTextFormat(Qt::PlainText);
        playerExitBut = new QPushButton(onePlayerScreen);
        playerExitBut->setObjectName(QString::fromUtf8("playerExitBut"));
        playerExitBut->setGeometry(QRect(10, 170, 101, 71));
        playerExitBut->setMaximumSize(QSize(480, 272));

        retranslateUi(onePlayerScreen);

        QMetaObject::connectSlotsByName(onePlayerScreen);
    } // setupUi

    void retranslateUi(QDialog *onePlayerScreen)
    {
        onePlayerScreen->setWindowTitle(QApplication::translate("onePlayerScreen", "Single Player", 0, QApplication::UnicodeUTF8));
        playerLabel->setText(QApplication::translate("onePlayerScreen", "Score:", 0, QApplication::UnicodeUTF8));
        playerExitBut->setText(QApplication::translate("onePlayerScreen", "Exit Mode", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class onePlayerScreen: public Ui_onePlayerScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEPLAYERSCREEN_H
