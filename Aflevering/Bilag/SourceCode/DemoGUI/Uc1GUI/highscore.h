#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QDialog>

namespace Ui {
class Highscore;
}

class Highscore : public QDialog
{
    Q_OBJECT

public:
    explicit Highscore(QWidget *parent = 0);
    ~Highscore();

private slots:
    void on_setHiBut_clicked();

    void on_clearHiBut_clicked();

    void on_exitHiBut_clicked();

private:
    Ui::Highscore *ui;
};

#endif // HIGHSCORE_H
