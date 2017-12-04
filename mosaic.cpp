#include "Mosaic.h"

using namespace cv;
using namespace std;


Mosaic::Mosaic(Mat *test_picture){
    this -> frame = test_picture;
}

Mat* Mosaic::Do_Mosaic(vector<Rect> face_all) {

    for(int faces = 0; faces < face_all.size(); faces++){

        Rect face = face_all.at(faces);

        int cnts = 0;
        int mb = 9;
        int wPoint = 0;
        int hPoint = 0;
        int xStartPoint = 0;
        int yStartPoint = 0;
        double R = 0;
        double G = 0;
        double B = 0;

        for (int i = 0; i < face.height / mb; i++) {
            for (int j = 0; j < face.width / mb; j++) {
                cnts = 0;
                B = 0;
                G = 0;
                R = 0;
                xStartPoint = face.x + (j * mb);
                yStartPoint = face.y + (i * mb);

                // 이미지의 픽셀 값의 r, g, b 값의 각각 합을 구함
                for (int mbY = yStartPoint; mbY < yStartPoint + mb; mbY++) {
                for (int mbX = xStartPoint; mbX < xStartPoint + mb; mbX++) {
                        wPoint = mbX;
                        hPoint = mbY;

                        if (mbX >= frame->cols) {
                            wPoint = frame->cols - 1;
                        }
                        if (mbY >= frame->rows){
                        hPoint = frame->rows - 1;
                        }

                        cv::Vec3b color = frame->at<cv::Vec3b>(hPoint, wPoint);
                        B += color.val[0];
                        G += color.val[1];
                        R += color.val[2];
                        cnts++;
                    }
                }

                // r, g, b 값의 평균 산출
                B /= cnts;
                G /= cnts;
                R /= cnts;

                // 모자이크 색상 생성
                cv::Scalar color;
                color.val[0] = B;
                color.val[1] = G;
                color.val[2] = R;

                // 프레임에 모자이크 이미지 삽입
                cv::rectangle(
                    *frame,
                    cvPoint(xStartPoint, yStartPoint),
                    cvPoint(xStartPoint + mb, yStartPoint + mb),
                    color,
                    CV_FILLED,
                    8,
                    0
                );
            }
        }
    }

    return frame;
}
