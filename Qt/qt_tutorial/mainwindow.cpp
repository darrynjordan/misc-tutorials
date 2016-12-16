#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "opencv2/opencv.hpp"


using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->show_image, SIGNAL(clicked(bool)), this, SLOT(button_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_clicked()
{
    Mat img = imread("/home/darryn/Pictures/profile_picture.JPG");
    cv::resize(img, img, Size(ui->display_image->width(), ui->display_image->height()), 0, 0, INTER_LINEAR);
    cv::cvtColor(img,img,CV_BGR2RGB);
    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->display_image->setPixmap(QPixmap::fromImage(imdisplay));
}
