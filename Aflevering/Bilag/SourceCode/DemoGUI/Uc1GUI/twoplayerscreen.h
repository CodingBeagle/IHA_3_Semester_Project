#ifndef TWOPLAYERSCREEN_H
#define TWOPLAYERSCREEN_H

#include <QDialog>

namespace Ui {
class twoPlayerScreen;
}

class twoPlayerScreen : public QDialog
{
    Q_OBJECT

public:
    explicit twoPlayerScreen(QWidget *parent = 0);
    friend class gameChoice;
    ~twoPlayerScreen();



private slots:
    void on_twoExitBut_clicked();
    void setTestScores();


private:
    Ui::twoPlayerScreen *ui;
};

#endif // TWOPLAYERSCREEN_H
