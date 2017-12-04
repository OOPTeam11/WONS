#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Mosaic.h"

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
        cv::resize(originMatImage, originMatImage, Size(400,500), 0, 0, CV_INTER_LINEAR);

        std::cout<< fileName.toStdString().c_str() <<std::endl;
        if(image.isNull()){
            QMessageBox::information(this,"Image Viewer","Error Displaying image");
            return;
        }
        String face_cascade = "../WONS/resource/haarcascade_frontalface_default.xml";   //학습된 정보에요
        String eye_cascade = "../WONS/resource/haarcascade_eye.xml";                   //학습된 정보에요

        Mat gray; // ju
        CascadeClassifier face; //얼굴 정보 저장소
        CascadeClassifier eye; // 눈 정보 저장소
        //load
        if(!face.load(face_cascade) || !eye.load(eye_cascade)){
            cout << "Cascade fail" << endl;
        }
        //face tracker
        cvtColor(originMatImage, gray, CV_RGB2GRAY);
        face.detectMultiScale(gray,face_pos, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(10,10));
        //~face tracker

        /*face check
        for(int i = 0; i<(int)face_pos.size();i++){
           // rectangle(originMatImage, face_pos[i], Scalar(0,255,0),2);
        }
        ~face check*/

        //eye tracker
        for(int i=0;i<(int)face_pos.size();i++){
            Mat roi = gray(face_pos[i]);
            eye.detectMultiScale(roi,eye_pos,1.1,3,0 |CV_HAAR_SCALE_IMAGE,Size(10,10));

            /*eye check
            for(int j=0;j<(int)eye_pos.size();j++){
                Point center(face_pos[i].x + eye_pos[j].x+(eye_pos[j].width/2),face_pos[i].y+eye_pos[j].y+(eye_pos[j].height/2));

                int radius = cvRound((eye_pos[j].width+eye_pos[j].height)*0.2);
                //circle(originMatImage, center, radius, Scalar(0,0,255),2);
            }
            ~eye check*/
        }

        //image = cvMatToQImage(originMatImage);  // 네모랑 동그라미를  확인하고싶으면 주석풀어요
        //~eye tracker
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

    Mat deco = imread("/home/caucse/다운로드/rudolph.png", cv::ImreadModes::IMREAD_UNCHANGED);
    //deco.resize(Size(500,500));


    //get face point
    //according to face point, resize & rotate deco image
    //overlay deco image

    decoImage di = decoImage();

    cv::resize(deco, deco, cv::Size(face_pos[0].size()), 0, 0, CV_INTER_LINEAR);
    for(int i=0;i<(int)face_pos.size();i++){
        Point center(face_pos[i].x, face_pos[i].y - face_pos[i].height);
        convertMatImage = di.AddImage(convertMatImage, deco, center);
    }

    /* heart
    cv::resize(deco, deco, cv::Size(50, 50), 0, 0, CV_INTER_LINEAR);
    for(int i=0;i<(int)face_pos.size();i++){
        Point center((face_pos[i].x + face_pos[i].width/9), (face_pos[i].y + face_pos[i].height/9*4));
        convertMatImage = di.AddImage(convertMatImage, deco, center);

        Point center2((face_pos[i].x + face_pos[i].width/9*6), (face_pos[i].y + face_pos[i].height/9*4));
        convertMatImage = di.AddImage(convertMatImage, deco, center2);
    }
    */

    /* 볼터치
    cv::resize(deco, deco, cv::Size(60, 60), 0, 0, CV_INTER_LINEAR);
    for(int i=0;i<(int)face_pos.size();i++){
        Point center((face_pos[i].x + face_pos[i].width/9), (face_pos[i].y + face_pos[i].height/9*4));
        convertMatImage = di.AddImage(convertMatImage, deco, center);

        Point center2((face_pos[i].x + face_pos[i].width/9*6), (face_pos[i].y + face_pos[i].height/9*4));
        convertMatImage = di.AddImage(convertMatImage, deco, center2);
    }
    */

    /* cat
    cv::resize(deco, deco, cv::Size(face_pos[0].size()*2), 0, 0, CV_INTER_LINEAR);
    //Point center((face_pos[0].x + face_pos[0].width/2), (face_pos[0].y + face_pos[0].height/2));
    convertMatImage = di.AddImage(convertMatImage, deco, Point(face_pos[0].x - (face_pos[0].width/2), face_pos[0].y - (face_pos[0].height/2)));
    */

    //cvMat is opencv Mat struct
    QImage image = cvMatToQImage(convertMatImage);
    //convert image set
    convertImage->setPixmap(QPixmap::fromImage(image));
}



//모자이크 - 장예솔
void MainWindow::on_Mosaic_clicked()
{
    //to do
    Mosaic mosaic_image = Mosaic(&originMatImage);

    convertMatImage = *mosaic_image.Do_Mosaic(face_pos);

    //cvMat is opencv Mat struct
    QImage image = cvMatToQImage(convertMatImage);
    //convert image set
    convertImage->setPixmap(QPixmap::fromImage(image));
}

//점 (자동) 없애기 - 허정우
int rect_size=10;

void onChange(int pos, void* param){}

void onMouseEvent(int event, int x, int y, int flags, void* dstImage){
    Mat mouseImage = *(Mat*)dstImage;
    createTrackbar("size", "convertImage", &rect_size, 255, onChange, (void*)&mouseImage);

    if(event != CV_EVENT_LBUTTONDOWN){
        cout << "size :: " << rect_size << endl;
        Mat tempImage = mouseImage.clone();
        Rect unClickedRect(x-(rect_size/2), y-(rect_size/2), rect_size, rect_size);
        rectangle(tempImage, unClickedRect, Scalar(255,0,0),1);
        imshow("convertImage", tempImage);

    }else if(event == CV_EVENT_LBUTTONDOWN){
        Rect clickedRect(x-(rect_size/2), y-(rect_size/2), rect_size, rect_size);
        Mat mask = getStructuringElement(MORPH_RECT, Size(3,3), Point(1,1));

        dilate((*(Mat*)dstImage)(clickedRect), mouseImage(clickedRect), mask,Point(-1,-1),3);
        erode((*(Mat*)dstImage)(clickedRect), mouseImage(clickedRect), mask,Point(-1,-1),3);
        medianBlur((*(Mat*)dstImage)(clickedRect), mouseImage(clickedRect),5);

        imshow("convertImage", mouseImage);
    }
}

void MainWindow::on_calibration_clicked()
{
    //to do
    convertMatImage = originMatImage;
    namedWindow("convertImage");
    imshow("convertImage", convertMatImage);
    setMouseCallback("convertImage", onMouseEvent, (void*)&convertMatImage);

    if(cvWaitKey() == 'q'){
        destroyWindow("convertImage");
    }

    //cvMat is opencv Mat struct
    QImage image = cvMatToQImage(convertMatImage);
    //convert image set
    convertImage->setPixmap(QPixmap::fromImage(image));
}

//얼굴 바꾸기 - 조민규
void MainWindow::on_convertFace_clicked()
{
    //to do
    FaceReplace *faceReplace = new FaceReplace();
    cout << "create face replace object" << endl;
    faceReplace->loadImageData(&originMatImage, &face_pos, &eye_pos);
    cout << "load data from main" << endl;
    faceReplace->selectDomainFace(0);
    cout << "select 0" << endl;
    faceReplace->replaceAllFace();
     cout << "replace" << endl;
    convertMatImage = *faceReplace->getChangedImage();

    //cvMat is opencv Mat struct
    QImage image = cvMatToQImage(convertMatImage);
    //convert image set
    convertImage->setPixmap(QPixmap::fromImage(image));

    // to save mem
    faceReplace->releaseCopiedImage();
}


/*
qt에서 이미지를 표시하려면 QPixmap으로 변경해야 합니다.
아래 소스코드는 변경하는 방법입니다.
QImage = cvMatToQImage( cvMat);
*/
