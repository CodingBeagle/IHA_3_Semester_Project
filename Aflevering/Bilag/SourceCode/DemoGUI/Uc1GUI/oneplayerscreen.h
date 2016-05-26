#ifndef ONEPLAYERSCREEN_H
#define ONEPLAYERSCREEN_H

#include <QDialog>

namespace Ui {
class onePlayerScreen;
}

class onePlayerScreen : public QDialog
{
    Q_OBJECT

public:
    explicit onePlayerScreen(QWidget *parent = 0);
    friend class gameChoice;
    ~onePlayerScreen();

private slots:
    void on_playerExitBut_clicked();
    void setTestScores();

private:
    Ui::onePlayerScreen *ui;
};

#endif // ONEPLAYERSCREEN_H
