#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <adafruit_uart.h>

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
    void on_pushButton_Open_clicked();

    void on_pushButton_GetData_clicked();

private:
    Ui::MainWindow *ui;

    Adafruit_UART ada;
};

#endif // MAINWINDOW_H
