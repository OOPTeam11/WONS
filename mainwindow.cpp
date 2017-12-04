#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QGraphicsScene setting
    //GraphicsView > GraphicScene > item
    originScene = new QGraphicsScene(this);
    convertScene = new QGraphicsScene(this);
    originImage = new QGraphicsPixmapItem();
    convertImage = new QGraphicsPixmapItem();
    originScene->addItem(originImage);
    convertScene->addItem(convertImage);
    ui->originGraphicsView->setScene(originScene);
    ui->convertGraphicsView->setScene(convertScene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openButton_clicked()
{
    const QString fileName = QFileDialog::getOpenFileName(this,"Open Image File",QDir::currentPath());
    if (!fileName.isEmpty())
        openFile(fileName);
}


void MainWindow::openFile(const QString &fileName){
    if(!fileName.isEmpty()){
        //image read
        QImage image(fileName);
        originMatImage =  imread(fileName.toStdString().c_str());

        std::cout<< fileName.toStdString().c_str() <<std::endl;
        if(image.isNull()){
            QMessageBox::information(this,"Image Viewer","Error Displaying image");
            return;
        }
        originImage->setPixmap(QPixmap::fromImage(image));

    }
}

/* 기본 사용법
 *
 * 먼저 opencv를 이용하여 영상처리를 하기 위해 "열기" 버튼을 눌러 이미지를 엽니다
 * 이미지가 열리면서 originMatImage라는 Mat구조체에 원본 이미지 파일 정보가 저장됩니다.
 * (originMatImage이 원본 이미지가 저장되어 있는 Mat 구조체, convertMatmage 변환되어 나올 이미지 Mat 구조체)
 * 여러분은 originMatImage구조체를 이용하여 영상처리를 하고 난 결과물을 convertMatImage에 저장하면 됩니다
 * (qt에서 이미지를 표현하기 위해 QPixmap구조체로 변환해야하기 때문입니다. 이부분은 제가 구현해 놓았습니다.)
 *
 */

//그림 입히기 - 이설희
void MainWindow::on_covertImage_clicked()
{
    //to do

    convertMatImage = originMatImage.clone();
    Mat deco = imread("/home/seolhee/사진/decoROI.png", cv::ImreadModes::IMREAD_UNCHANGED);
    //resize(deco, deco, Size(deco.cols / 3.3, deco.rows / 3.3));

    //convertMatImage = BlendingPixel(convertMatImage, deco, Point(210, 60));

    //get face point
    //according to face point, resize & rotate deco image
    //overlay deco image




    //cvMat is opencv Mat struct
    QImage image = cvMatToQImage(mbgrImgResult);
    //convert image set
    convertImage->setPixmap(QPixmap::fromImage(image));
}



//모자이크 - 장예솔
void MainWindow::on_Mosaic_clicked()
{
    //to do



    //cvMat is opencv Mat struct
    QImage image = cvMatToQImage(convertMatImage);
    //convert image set
    convertImage->setPixmap(QPixmap::fromImage(image));
}

//점 (자동) 없애기 - 허정우
void MainWindow::on_calibration_clicked()
{
    //to do



    //cvMat is opencv Mat struct
    QImage image = cvMatToQImage(convertMatImage);
    //convert image set
    convertImage->setPixmap(QPixmap::fromImage(image));
}

//얼굴 바꾸기 - 조민규
void MainWindow::on_convertFace_clicked()
{
    //to do



    //cvMat is opencv Mat struct
    QImage image = cvMatToQImage(convertMatImage);
    //convert image set
    convertImage->setPixmap(QPixmap::fromImage(image));
}


/*
qt에서 이미지를 표시하려면 QPixmap으로 변경해야 합니다.
아래 소스코드는 변경하는 방법입니다.
QImage = cvMatToQImage( cvMat);
*/
