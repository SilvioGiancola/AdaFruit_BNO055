#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <adafruit_uart.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <vtkRenderWindow.h>        // for the rendering window (QT & VTK)

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

    void on_pushButton_Close_clicked();

    void on_pushButton_Init_clicked();

    void on_pushButton_GetQuat_clicked();

    void on_pushButton_Gyr_clicked();

    void on_pushButton_GetEul_clicked();

    void on_pushButton_GetAcc_clicked();

    void on_pushButton_GetGrv_clicked();

    void on_pushButton_GetMag_clicked();

    void on_pushButton_Lia_clicked();

private:
    Ui::MainWindow *ui;

    Adafruit_UART ada;
    pcl::visualization::PCLVisualizer::Ptr viewer;
};

#endif // MAINWINDOW_H
