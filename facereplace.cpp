#include "FaceReplace.h"

using namespace std;
using namespace cv;

void FaceReplace::loadImageData(Mat *originImageMat, vector<Rect> *faces, vector<Rect> *eyes){
    // # copying image part
    // if copied image already exist, free image
    if (!this->copiedImageMat.empty()){releaseCopiedImage();}
    this->copiedImageMat = originImageMat->clone();

    // # connect vector data part
    this->faces = faces;
    this->eyes = eyes;

    return;
}

void FaceReplace::selectDomainFace(int index){
    if (0 <= index && index < faces->size()){
        domainFace = faces->at(index);
    }
    else {
        domainFace = *(faces->begin());
    }
}

bool isEqual(Rect &r1, Rect &r2){
    return (r1.x == r2.x) &&
            (r1.y == r2.y) &&
            (r1.width == r2.width) &&
            (r1.height == r2.height);
}

void FaceReplace::replaceAllFace(){
    // ROI(Region of interest) : region that we need to modify

    // Matrix of domain rect. to get image of domain
    Mat domainImageMat = copiedImageMat(domainFace);
    imshow("domain image", domainImageMat);

    for (int index = 0; index < faces->size(); index++){
        if (!isEqual(domainFace, faces->at(index))){

            // test
            cout << index << " test" << endl;
            //string title = to_string(index) + "nd";
            //imshow(title, copiedImageMat(faces->at(index)));
            // test
            Rect face = faces->at(index);
            Mat dst;
            cv::resize(domainImageMat, dst, cv::Size(face.width, face.height), 0, 0, CV_INTER_LINEAR);
            dst.copyTo(copiedImageMat(Rect(face.x, face.y, face.width, face.height)));
        }
    }
}

Mat* FaceReplace::getChangedImage(){
    return &copiedImageMat;
}

void FaceReplace::releaseCopiedImage(){
    this->copiedImageMat.release();
}
