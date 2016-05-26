#ifndef GAMECHOICE_H
#define GAMECHOICE_H

#include <QDialog>

namespace Ui {
class gameChoice;
}

class gameChoice : public QDialog
{
    Q_OBJECT

public:
    explicit gameChoice(QWidget *parent = 0);
    ~gameChoice();

private slots:
    void on_choiceOne_clicked();

    void on_choiceTwo_clicked();

    void on_choiceExitBut_clicked();

private:
    Ui::gameChoice *ui;
};

#endif // GAMECHOICE_H
