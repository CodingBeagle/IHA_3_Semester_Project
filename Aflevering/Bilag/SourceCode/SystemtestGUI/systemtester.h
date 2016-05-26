#ifndef SYSTEMTESTER_H
#define SYSTEMTESTER_H

#include <QMainWindow>

namespace Ui {
class Systemtester;
}

class Systemtester : public QMainWindow
{
    Q_OBJECT

public:
    explicit Systemtester(QWidget *parent = 0);
    ~Systemtester();

private slots:
    void on_activateBut_clicked();

    void on_clearBut_clicked();

    void on_exitBut_clicked();


private:
    Ui::Systemtester *ui;
};

#endif // SYSTEMTESTER_H
