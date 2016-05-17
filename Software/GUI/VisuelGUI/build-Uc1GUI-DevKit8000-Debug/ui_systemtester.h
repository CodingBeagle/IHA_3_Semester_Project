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
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_systemtester
{
public:
    QTextBrowser *systemText;
    QPushButton *activateBut;
    QPushButton *clearBut;
    QPushButton *exitBut;

    void setupUi(QDialog *systemtester)
    {
        if (systemtester->objectName().isEmpty())
            systemtester->setObjectName(QString::fromUtf8("systemtester"));
        systemtester->setWindowModality(Qt::NonModal);
        systemtester->resize(480, 272);
        systemtester->setMaximumSize(QSize(480, 272));
        systemText = new QTextBrowser(systemtester);
        systemText->setObjectName(QString::fromUtf8("systemText"));
        systemText->setGeometry(QRect(110, 10, 351, 241));
        activateBut = new QPushButton(systemtester);
        activateBut->setObjectName(QString::fromUtf8("activateBut"));
        activateBut->setGeometry(QRect(10, 10, 91, 121));
        QFont font;
        font.setPointSize(12);
        activateBut->setFont(font);
        activateBut->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/background.jpg);"));
        clearBut = new QPushButton(systemtester);
        clearBut->setObjectName(QString::fromUtf8("clearBut"));
        clearBut->setGeometry(QRect(10, 130, 91, 61));
        exitBut = new QPushButton(systemtester);
        exitBut->setObjectName(QString::fromUtf8("exitBut"));
        exitBut->setGeometry(QRect(10, 190, 91, 61));

        retranslateUi(systemtester);

        QMetaObject::connectSlotsByName(systemtester);
    } // setupUi

    void retranslateUi(QDialog *systemtester)
    {
        systemtester->setWindowTitle(QApplication::translate("systemtester", "System Test", 0, QApplication::UnicodeUTF8));
        activateBut->setText(QApplication::translate("systemtester", "Start Test", 0, QApplication::UnicodeUTF8));
        clearBut->setText(QApplication::translate("systemtester", "Clear", 0, QApplication::UnicodeUTF8));
        exitBut->setText(QApplication::translate("systemtester", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class systemtester: public Ui_systemtester {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMTESTER_H
