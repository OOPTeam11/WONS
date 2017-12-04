#include "decoimage.h"

decoImage::decoImage()
{

}

Mat decoImage::AddImage(Mat baseImage, Mat deco, const Point& location){

    Mat result = baseImage.clone();
    for (int y = std::max(location.y, 0); y < baseImage.rows; ++y)
    {
        int fY = y - location.y;
        if (fY >= deco.rows)
            break;
        for (int x = std::max(location.x, 0); x < baseImage.cols; ++x)
        {
        int fX = x - location.x;
        if (fX >= deco.cols)
            break;
        double opacity = ((double)deco.data[fY * deco.step + fX * deco.channels() + 3]) / 255.;
            for (int c = 0; opacity > 0 && c < baseImage.channels(); ++c)
            {
            unsigned char decoPx = deco.data[fY * deco.step + fX * deco.channels() + c];
            unsigned char basePx = baseImage.data[y * baseImage.step + x * baseImage.channels() + c];
            result.data[y * baseImage.step + baseImage.channels() * x + c] = basePx * (1. - opacity) + decoPx * opacity;
            }
        }
    }
    return result;
}
\
void decoImage::RotateImage(Mat &src, Mat &dst, int degree) {
    //이미지 사이즈
    double height = dst.rows;
    double width = dst.cols;

    //회전 중심점
    int centerY = height/2;
    int centerX = width/2;

    //angle -> radian
    double seta = -degree*3.141592/180.0;
    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++) {
            int newY = (x-centerX)*sin(seta)+(y-centerY)*cos(seta)+centerY;
            int newX = (y-centerY)*cos(seta)+(y-centerY)*sin(seta)+centerX;

            if((newX<0.0) || (newX>=width) || (newY<0.0) || (newY>=height)) {
                dst.at<Vec3b>(y,x)=0;
            }
            else {
                Vec3b colVal = src.at<Vec3b>(newY, newX);
                dst.at<Vec3b>(y,x) = colVal;
            }
        }
    }
}
