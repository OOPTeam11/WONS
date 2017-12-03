#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include <QObject>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QDir>
#include <QDebug>
#include <QImage>
#include <QString>
#include <QResource>
#include <opencv2/opencv.hpp>

class FaceDetector : public QObject
{
    Q_OBJECT
    QString facecascade_filename_;  //  얼굴인식 정보
    QString eyecascade_filename_;   // 눈 인식 정보
    QBasicTimer timer_; // 타이머 제한을 둘 경우 사용
    cv::Mat frame_; // 이미지 불러오기
    bool processAll_;   // 처리현황
    cv::CascadeClassifier faceCascade;
    cv::CascadeClassifier eyeCascade;

    void process(cv::Mat frame);
    void loadFiles(cv::String facecascade_filename, cv::String eyecascade_filename);
    void queue(const cv::Mat & Frame);
    void timerEvent(QTimerEvent* ev);
    static void matDeleter(void* mat);

public:
    FaceDetector(QObject *parent = 0) : QObject(parent), processAll_(true){
        facecascade_filename_ = "resources/haarcascade_frontalface_default.xml";
        eyecascade_filename_ = "resources/haarcascade_eye.xml";
        loadFiles(facecascade_filename_.toStdString().c_str(), eyecascade_filename_.toStdString().c_str());
    }
    void setProcessAll(bool all);
    ~FaceDetector();

signals:
    void image_signal(const QImage&);

public slots:
    void processFrame(const cv::Mat& frame);
    void facecascade_filename(QString filename);

};

#endif // FACEDETECTOR_H
