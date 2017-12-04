#ifndef MOSAIC_H
#define MOSAIC_H
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

class Mosaic{

private:
       cv::Mat *frame;


public:
       Mosaic(cv::Mat *frame);
       Mat* Do_Mosaic(vector<Rect> face_all);

};
#endif // MOSAIC_H
