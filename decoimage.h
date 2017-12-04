#ifndef CONVERTIMAGE_H
#define CONVERTIMAGE_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

class decoImage
{
public:
    decoImage();
    Mat AddImage(Mat baseImage, Mat deco, const Point&);
    void RotateImage(Mat &img1, Mat &img2, int degree);
};

#endif // CONVERTIMAGE_H
