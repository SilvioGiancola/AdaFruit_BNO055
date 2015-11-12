#ifndef ADAFRUIT_UC_H
#define ADAFRUIT_UC_H
/******************/
/*** ADAFRUIT DRIVERS ***/
/******************/
/******************/
#include <QSerialPort>
#include <QSerialPortInfo>
#include <iostream>
#include <QTime>

#define SUCCESS 0
#define ERR_BAUDRATE 1
#define ERR_DATABITS 2
#define ERR_PARITY 3
#define ERR_STOPBITS 4
#define ERR_FLOWCONTROL 5
#define ERR_OPEN 6
#define ERR_PLUG 7
#define ERR_MESSAGE 8

/*
(0) *help?
(1) *info?
(2) *baud[:{<rate>|list}]?
(3) *mode[:{list|text|bin}]?
(4) *endian?
(5) *reset?
(6) *status?
(7) *unit[:{list | what | what:set}]?
(8) *accel?
(9) *euler?
(A) *grav?
(B) *gyro?
(C) *mag?
(D) *quat?
(E) *temp[:A|G|M]?
(F) *fw?
(G) *echo[:{on|off}]?
(I) *cal?
*/


#include <QWidget>
#include <QThread>
#include <eigen3/Eigen/Geometry>

class Adafruit_uC : public QSerialPort
{
    Q_OBJECT
public:

    // Constructor
    explicit Adafruit_uC(QWidget *parent = 0) : QSerialPort(parent)
    {
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            if (info.description() == QString("USB-Serial Controller"))
                if (info.manufacturer() == QString("Prolific Technology Inc."))
                    if(info.vendorIdentifier() == 0x067b)
                        if(info.productIdentifier() == 0x2303)
                            setPortName(info.portName());

        }

        plugged = true;
        if (this->portName().isEmpty())
            plugged = false;
    }



    int Open()
    {
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            if (info.description() == QString("USB-Serial Controller"))
                if (info.manufacturer() == QString("Prolific Technology Inc."))
                    if(info.vendorIdentifier() == 0x067b)
                        if(info.productIdentifier() == 0x2303)
                            setPortName(info.portName());

        }

        plugged = true;
        if (this->portName().isEmpty())
            plugged = false;


        if (!plugged)
            return ERR_PLUG;

        if (!open(QIODevice::ReadWrite))
            return ERR_OPEN;

        if (!setBaudRate(QSerialPort::Baud115200))
            return ERR_BAUDRATE;

        if (!setDataBits(QSerialPort::Data8))
            return ERR_DATABITS;

        if (!setParity(QSerialPort::NoParity))
            return ERR_PARITY;

        if (!setStopBits(QSerialPort::UnknownStopBits))
            return ERR_STOPBITS;

        if (!setFlowControl(QSerialPort::HardwareControl))
            return ERR_FLOWCONTROL;


     //   Question(QString("*echo:off?"));



        return SUCCESS;

    }



    QString GetCal()
    {
        // send *cal?, get answer and return it
        return  Ask(QString("*cal?"));
    }

    Eigen::Quaternionf GetQuat()
    {
        // send *quat?, get answer, convert it and return it
        return ConvertToQuat(Ask(QString("*quat?")));
    }



    Eigen::Quaternionf ConvertToQuat(QString answer)
    {
        // convert string in quaternions
        QStringList quatList = answer.section("!",0,0).split(":");
        Eigen::Quaternionf quat;
        if (quatList.size() > 4)
        {
            quat.w() = quatList.at(1).toFloat();
            quat.x() = quatList.at(2).toFloat();
            quat.y() = quatList.at(3).toFloat();
            quat.z() = quatList.at(4).toFloat();
        }

        return quat;
    }




    QString Ask(QString question)
    {
        if (Question(question) != SUCCESS)
            return QString();

        return Answer();
    }

    int Question(QString question)
    {
        // check opening
        if (!isOpen() || !plugged)
            return ERR_OPEN;

        // remove previous message
        readAll();

        // Ask for quaternion string
        if (write(question.toLocal8Bit()) == -1)
              return ERR_MESSAGE;

        return SUCCESS;
    }

    QString Answer()
    {
        // init Answer
        QString answer;

        // get answer in a single string
        while (waitForReadyRead (100) && !(answer.endsWith("!")) )
            answer.append(QString(readAll()));

        // return answer
        return answer;
    }

private:
    bool plugged;


};

#endif // ADAFRUIT_UC_H
