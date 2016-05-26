#ifndef SYSTEMTESTER_H
#define SYSTEMTESTER_H

#include <QDialog>

namespace Ui {
class systemtester;
}

class systemtester : public QDialog
{
    Q_OBJECT

public:
    explicit systemtester(QWidget *parent = 0);
    ~systemtester();

private slots:
    void on_activateBut_clicked();

    void on_clearBut_clicked();

    void on_exitBut_clicked();

private:
    Ui::systemtester *ui;
};

#endif // SYSTEMTESTER_H
