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
#include "faceDetector.h" //주현

#include "asmOpenCV.h"

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
    FaceDetector* facedetector_;  // 주현 페이스 디텍터 선언
    // QThread faceDetectThread_; 혹시 쓰레드 필요한 경우 쓰ㅅㅔ영

private slots:

    void on_openButton_clicked(); // open file using qt
    void openFile(const QString &fileName); // file open process
    void on_covertImage_clicked(); //그림 입히기 - 이설희
    void on_Mosaic_clicked(); //모자이크 - 장예솔
    void on_calibration_clicked(); //점 (자동) 없애기 - 허정우
    void on_convertFace_clicked(); //얼굴 바꾸기 - 조민규

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
