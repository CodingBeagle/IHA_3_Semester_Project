#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SimulCandyGun.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_SPITestBut_clicked();

    void on_I2CTestBut_clicked();

    void on_WiiTestBut_clicked();

    void fullTest();

    void on_ExitBut_clicked();


    void on_ClearBut_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
