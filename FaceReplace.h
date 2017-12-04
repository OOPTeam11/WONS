#ifndef FACECHANGE_H
#define FACECHANGE_H

#include <vector>
#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

#define Debug

/*
Design

1. loadImageData :setting FaceData and copying original image

2. selectDomainFace : selectting face to copy

3. replaceAllFace : replace all face with selected face

4. returnImage : return image

*/

class FaceReplace{
public :

    // init all data. copy origin image
    void loadImageData(Mat *originImageMat = 0, vector<Rect> *faces = 0, vector<Rect> *eyes = 0);
    // select face to copy
    void selectDomainFace(int index);
    // replace all face with selected face
    void replaceAllFace();
    // return image
    Mat* getChangedImage();
    // free image
    void releaseCopiedImage();

private:
    Mat copiedImageMat;
    //FaceData faceData
    Rect domainFace;
    vector<Rect> *faces;
    vector<Rect> *eyes;
};

#endif // FACECHANGE_H
