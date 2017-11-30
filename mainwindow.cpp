#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openButton_clicked()
{
    const QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        openFile(fileName);
}


void MainWindow::openFile(const QString &fileName){

}

//그림 입히기 - 이설희
void MainWindow::on_covertImage_clicked()
{

}

//모자이크 - 장예솔
void MainWindow::on_Mosaic_clicked()
{

}

//점 (자동) 없애기 - 허정우
void MainWindow::on_calibration_clicked()
{

}

//얼굴 바꾸기 - 조민규
void MainWindow::on_convertFace_clicked()
{

}
