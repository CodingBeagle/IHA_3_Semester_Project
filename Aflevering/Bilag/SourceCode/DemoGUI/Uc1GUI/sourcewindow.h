#ifndef SOURCEWINDOW_H
#define SOURCEWINDOW_H

#include <QMainWindow>

namespace Ui {
class SourceWindow;
}

class SourceWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SourceWindow(QWidget *parent = 0);
    ~SourceWindow();

private slots:
    void on_exitBut_clicked();

    void on_scoreBut_clicked();

    void on_startBut_clicked();

    void on_testBut_clicked();

private:
    Ui::SourceWindow *ui;
};

#endif // SOURCEWINDOW_H
