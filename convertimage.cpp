#include "convertimage.h"

convertImage::convertImage()
{

}

Mat AddImage(Mat baseImage, Mat deco, const Point& location){

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
            mbgrImgResult.data[y * baseImage.step + baseImage.channels() * x + c] = basePx * (1. - opacity) + decoPx * opacity;
            }
        }
    }
    return result;
}
