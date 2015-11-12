#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),  ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Open_clicked()
{
    ada.Open();
    return;
}

void MainWindow::on_pushButton_GetData_clicked()
{
    Adafruit_Data * result = new Adafruit_Data();
    if (ada.ReadAllData(result)!=SUCCESS)
        return;

    // Accelerometer
    ui->lcdNumber_Accelerometer_X->display(result->m_accelerometer[0]);
    ui->lcdNumber_Accelerometer_Y->display(result->m_accelerometer[1]);
    ui->lcdNumber_Accelerometer_Z->display(result->m_accelerometer[2]);

    // Euler Angles
    ui->lcdNumber_Euler_X->display(result->m_euler_angles[0]);
    ui->lcdNumber_Euler_Y->display(result->m_euler_angles[1]);
    ui->lcdNumber_Euler_Z->display(result->m_euler_angles[2]);

    // Gravity
    ui->lcdNumber_Gravity_X->display(result->m_gravity[0]);
    ui->lcdNumber_Gravity_Y->display(result->m_gravity[1]);
    ui->lcdNumber_Gravity_Z->display(result->m_gravity[2]);

    // Gyroscope
    ui->lcdNumber_Gyroscope_X->display(result->m_gyroscope[0]);
    ui->lcdNumber_Gyroscope_Y->display(result->m_gyroscope[1]);
    ui->lcdNumber_Gyroscope_Z->display(result->m_gyroscope[2]);

    // Linear acceleration
    ui->lcdNumber_LinearAcceleration_X->display(result->m_linear_acceleration[0]);
    ui->lcdNumber_LinearAcceleration_Y->display(result->m_linear_acceleration[1]);
    ui->lcdNumber_LinearAcceleration_Z->display(result->m_linear_acceleration[2]);

    // Magnetometer
    ui->lcdNumber_Magnetometer_X->display(result->m_magnetometer[0]);
    ui->lcdNumber_Magnetometer_Y->display(result->m_magnetometer[1]);
    ui->lcdNumber_Magnetometer_Z->display(result->m_magnetometer[2]);

    // Quaternion
    ui->lcdNumber_Quaternion_W->display(result->m_quaternion.w());
    ui->lcdNumber_Quaternion_X->display(result->m_quaternion.x());
    ui->lcdNumber_Quaternion_Y->display(result->m_quaternion.y());
    ui->lcdNumber_Quaternion_Z->display(result->m_quaternion.z());

    // Temperature
    ui->lcdNumber_Temperature->display(result->m_temperature);

    return;
}
