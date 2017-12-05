#ifndef CONVERTIMAGE_H
#define CONVERTIMAGE_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv/highgui.h"

#include <vector>

using namespace std;
using namespace cv;

class decoImage
{
public:
    decoImage(Mat originMatImage, vector<Rect> *face_pos, int index);
    Mat AddImage(Mat baseImage, Mat deco, const Point&);
    Mat Deco();
    void RotateImage(Mat &img1, Mat &img2, int degree);
private:
    Mat originMatImage;
    Mat deco;
    int index;
    vector<Rect> *face_pos;
    enum{
        cat = 0,
        rudolph,
        cheek,
        blusher
    };
};

#endif // CONVERTIMAGE_H
