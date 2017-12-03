#ifndef FACECHANGE_H
#define FACECHANGE_H

#endif // FACECHANGE_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/*
Design

1. loadImageData :setting FaceData and copying original image

2. selectDomainFace : selectting face to copy

3. replaceAllFace : replace all face with selected face

4. returnImage : return image

*/

class FaceReplace{
public :
    void loadImageData();
    void selectDomainFace();
    void replaceAllFace();
    IplImage getChangedImage();
private:
    IplImage copiedImage;
    //FaceData faceData
}
