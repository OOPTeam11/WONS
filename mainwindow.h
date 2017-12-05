#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QString>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include "decoimage.h"
#include "asmOpenCV.h"

#include "FaceReplace.h"


using namespace ASM;
using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    vector<Rect> face_pos; //ju 얼굴이랑 눈 도형이에요 얼굴은 네모 눈은 동그라미
    vector<Rect> eye_pos; // ju


private slots:

    void on_openButton_clicked(); // open file using qt
    void openFile(const QString &fileName); // file open process
    void on_covertImage_clicked(); //그림 입히기 - 이설희
    void on_Mosaic_clicked(); //모자이크 - 장예솔
    void on_calibration_clicked(); //점 (자동) 없애기 - 허정우
    void on_convertFace_clicked(); //얼굴 바꾸기 - 조민규


    void on_openButton_2_clicked();

    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *originScene;
    QGraphicsScene *convertScene;
    QGraphicsPixmapItem *originImage;
    QGraphicsPixmapItem *convertImage;
    Mat originMatImage;
    Mat convertMatImage;

};

#endif // MAINWINDOW_H
