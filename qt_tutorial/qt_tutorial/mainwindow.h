#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void button_clicked();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     QImage imdisplay;

private:
    Ui::MainWindow *ui;
};

#endif
