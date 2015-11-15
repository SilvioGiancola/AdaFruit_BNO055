#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),  ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create 3D Viewer
    viewer.reset(new pcl::visualization::PCLVisualizer("Viewer",false));
    ui->qvtkWidget->SetRenderWindow(viewer->getRenderWindow());

    viewer->addCoordinateSystem(1.0);
    // on_pushButton_CleanViewer_clicked();
    viewer->setCameraPosition(1,10,1, // mi posiziono dietro ad un Kinect
                              0.5,0.5,0.5, // guardo un punto centrale
                              0,0,1);   // orientato con la z verso l'alto
    viewer->setCameraClipDistances(-10,10);
    viewer->setBackgroundColor (0.5, 0.5, 0.5);
    ui->qvtkWidget->update ();



    viewer->setupInteractor(ui->qvtkWidget->GetInteractor(),ui->qvtkWidget->GetRenderWindow());
    viewer->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);


}

MainWindow::~MainWindow()
{
    ada.close();
    delete ui;
}

void MainWindow::on_pushButton_Open_clicked()
{
    ui->statusBar->showMessage("Adafruit BNO055 is opening, please wait ...");
    if (ada.Open() == SUCCESS)
    {
        ui->groupBox_Accelerometer->setEnabled(true);
        ui->groupBox_Euler->setEnabled(true);
        ui->groupBox_Gravity->setEnabled(true);
        ui->groupBox_Gyroscope->setEnabled(true);
        ui->groupBox_LinerarAcceleration->setEnabled(true);
        ui->groupBox_Magnetometer->setEnabled(true);
        ui->groupBox_Quaternion->setEnabled(true);
        ui->groupBox_Temperature->setEnabled(true);
        ui->statusBar->showMessage("AdaFruit BNO055 open!",5000);
    }
    else
        ui->statusBar->showMessage("Error in oppening AdaFruit BNO055");

    return;
}

void MainWindow::on_pushButton_Close_clicked()
{
    ada.close();
    ui->groupBox_Accelerometer->setEnabled(false);
    ui->groupBox_Euler->setEnabled(false);
    ui->groupBox_Gravity->setEnabled(false);
    ui->groupBox_Gyroscope->setEnabled(false);
    ui->groupBox_LinerarAcceleration->setEnabled(false);
    ui->groupBox_Magnetometer->setEnabled(false);
    ui->groupBox_Quaternion->setEnabled(false);
    ui->groupBox_Temperature->setEnabled(false);

    return;
}

void MainWindow::on_pushButton_Init_clicked()
{
    if (ada.Init() != SUCCESS)
    {
        return;
    }

    return;
}



void MainWindow::on_pushButton_GetData_clicked()
{
    QTime t;
    t.start();

    Adafruit_Data * result = new Adafruit_Data();
    if (ada.ReadAllData(result) != SUCCESS)
        return;

    ui->lcdNumber_Time->display(t.elapsed());

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


    viewer->removeAllCoordinateSystems();
    Eigen::Matrix4f trans = Eigen::Matrix4f::Identity();
    trans.block(0,0,3,3) = result->m_quaternion.matrix();
    viewer->addCoordinateSystem(1.0, Eigen::Affine3f(trans));
    ui->qvtkWidget->update();

    return;
}

void MainWindow::on_pushButton_Gyr_clicked()
{
    QTime t;
    t.start();

    Eigen::Vector3f result;
    if (ada.GetGyr(&result) != SUCCESS)
        return;

    ui->lcdNumber_Time->display(t.elapsed());

    // Gravity
    ui->lcdNumber_Gyroscope_X->display(result[0]);
    ui->lcdNumber_Gyroscope_Y->display(result[1]);
    ui->lcdNumber_Gyroscope_Z->display(result[2]);

}

void MainWindow::on_pushButton_GetEul_clicked()
{
    QTime t;
    t.start();

    Eigen::Vector3f result;
    if (ada.GetEul(&result) != SUCCESS)
        return;

    ui->lcdNumber_Time->display(t.elapsed());

    // Euler Angles
    ui->lcdNumber_Euler_X->display(result[0]);
    ui->lcdNumber_Euler_Y->display(result[1]);
    ui->lcdNumber_Euler_Z->display(result[2]);

/*
    viewer->removeAllCoordinateSystems();


    Eigen::Matrix4f trans = Eigen::Matrix4f::Identity();

    Eigen::Matrix3f m;
    m = Eigen::AngleAxisf(result[2]/10.0, Eigen::Vector3f::UnitZ())
            * Eigen::AngleAxisf(result[1]/10.0, Eigen::Vector3f::UnitY())
            * Eigen::AngleAxisf(result[0]/10.0, Eigen::Vector3f::UnitX());
    trans.block(0,0,3,3) = m;
    viewer->addCoordinateSystem(1.0, Eigen::Affine3f(trans));
    ui->qvtkWidget->update();*/
}

void MainWindow::on_pushButton_GetAcc_clicked()
{
    QTime t;
    t.start();

    Eigen::Vector3f result;
    if (ada.GetAcc(&result) != SUCCESS)
        return;

    ui->lcdNumber_Time->display(t.elapsed());

    // Accelerometer
    ui->lcdNumber_Accelerometer_X->display(result[0]);
    ui->lcdNumber_Accelerometer_Y->display(result[1]);
    ui->lcdNumber_Accelerometer_Z->display(result[2]);
}

void MainWindow::on_pushButton_GetGrv_clicked()
{
    QTime t;
    t.start();

    Eigen::Vector3f result;
    if (ada.GetGrv(&result) != SUCCESS)
        return;

    ui->lcdNumber_Time->display(t.elapsed());

    // Gravity
    ui->lcdNumber_Gravity_X->display(result[0]);
    ui->lcdNumber_Gravity_Y->display(result[1]);
    ui->lcdNumber_Gravity_Z->display(result[2]);
}

void MainWindow::on_pushButton_GetMag_clicked()
{
    QTime t;
    t.start();

    Eigen::Vector3f result;
    if (ada.GetMag(&result) != SUCCESS)
        return;

    ui->lcdNumber_Time->display(t.elapsed());

    // Magnetometer
    ui->lcdNumber_Magnetometer_X->display(result[0]);
    ui->lcdNumber_Magnetometer_Y->display(result[1]);
    ui->lcdNumber_Magnetometer_Z->display(result[2]);
}

void MainWindow::on_pushButton_Lia_clicked()
{
    QTime t;
    t.start();

    Eigen::Vector3f result;
    if (ada.GetLia(&result) != SUCCESS)
        return;

    ui->lcdNumber_Time->display(t.elapsed());

    // Linear acceleration
    ui->lcdNumber_LinearAcceleration_X->display(result[0]);
    ui->lcdNumber_LinearAcceleration_Y->display(result[1]);
    ui->lcdNumber_LinearAcceleration_Z->display(result[2]);
}

void MainWindow::on_pushButton_GetQuat_clicked()
{
    QTime t;
    t.start();

    Eigen::Quaternionf * result = new Eigen::Quaternionf();
    if (ada.GetQuat(result) != SUCCESS)
        return;

    ui->lcdNumber_Time->display(t.elapsed());

    // Quaternion
    ui->lcdNumber_Quaternion_W->display(result->w());
    ui->lcdNumber_Quaternion_X->display(result->x());
    ui->lcdNumber_Quaternion_Y->display(result->y());
    ui->lcdNumber_Quaternion_Z->display(result->z());


    viewer->removeAllCoordinateSystems();
    Eigen::Matrix4f trans = Eigen::Matrix4f::Identity();
    trans.block(0,0,3,3) = result->matrix();
    viewer->addCoordinateSystem(1.0, Eigen::Affine3f(trans));
    ui->qvtkWidget->update();
}



#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

