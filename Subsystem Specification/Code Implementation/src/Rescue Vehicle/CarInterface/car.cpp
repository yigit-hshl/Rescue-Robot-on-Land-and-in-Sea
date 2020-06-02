#include "car.h"
#include "ui_car.h"
//#include <QPixmap>



car::car(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::car)
{
    ui->setupUi(this);
//    QPixmap pixStart("C:/Users/Startklar/Documents/CarInteractionApplication/CarInterface/icons/startButton.jpg");
//    QPixmap pixStop("C:/Users/Startklar/Documents/CarInteractionApplication/CarInterface/icons/stopButton.jpg");
//    ui->startPushButton->setPixmap(pixStart.scaled(400,400));
//    ui->stopPushButton->setPixmap(pixStop.scaled(400,400));
}

car::~car()
{
    delete ui;
}



void car::on_helpButton_3_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
}

void car::on_statusButton_3_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void car::on_cameraButton_3_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}


