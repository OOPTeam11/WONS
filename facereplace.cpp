#include "FaceReplace.h"

void FaceReplace::loadImageData(IplImage *originImage = 0, vector<Rect> *faces = 0, vector<Rect> *eyes = 0){
    // # copying image part
    // if copied image already exist, free image
    if (this->copiedImage != NULL){releaseCopiedImage();}
    this->copiedImage = cvCloneImage(originImage);
    this->copiedImageMat = cvarrToMat(this->copiedImage);

    // # connect vector data part
    this->faces = faces;
    this->eyes = eyes;

    return;
}

void FaceReplace::selectDomainFace(int index){
    if (0 <= index && index < faces->size()){
        domainFace = faces[index];
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
    Mat domainImageMat = copiedImageMat(domainRect);
#ifdef Debug
    imshow("domain image", domainImageMat);
#endif

    for (int index = 0; index < faces->size(); i++){
        if (!isEqual(domainFace, faces[index])){
            Rect face = faces[index];
            domainImageMat.copyTo(copiedImageMat, face);
        }
    }
}

IplImage* FaceReplace::getChangedImage(){
    return copiedImage;
}

void releaseCopiedImage(){

}
