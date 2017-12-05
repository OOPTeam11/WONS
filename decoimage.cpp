#include "decoimage.h"

decoImage::decoImage(Mat originMatImage, vector<Rect> *face_pos, int index)
{
    this->originMatImage = originMatImage;
    this->index = index;
    this->face_pos = face_pos;
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
    return result.clone();
}

Mat decoImage::Deco() {
    Mat convertMatImage = originMatImage.clone();
    switch(index) {
    case cat:
        deco = imread("../WONS/resource/cat.png", cv::ImreadModes::IMREAD_UNCHANGED);
        for(int i=0;i<(int)face_pos->size();i++){
            cv::resize(deco, deco, cv::Size(face_pos->at(i).size()*2), 0, 0, CV_INTER_LINEAR);
            Point center(face_pos->at(i).x - (face_pos->at(i).width/2), face_pos->at(i).y - (face_pos->at(i).height/2));
            convertMatImage = AddImage(convertMatImage, deco, center);
        }
        break;
    case rudolph:
        deco = imread("../WONS/resource/rudolph.png", cv::ImreadModes::IMREAD_UNCHANGED);
        for(int i=0;i<(int)face_pos->size();i++){
            cv::resize(deco, deco, cv::Size(face_pos->at(i).size()), 0, 0, CV_INTER_LINEAR);
            Point center(face_pos->at(i).x, face_pos->at(i).y - face_pos->at(i).height);
            convertMatImage = AddImage(convertMatImage, deco, center);
        }
        break;
    case cheek:
        deco = imread("../WONS/resource/cheek.png", cv::ImreadModes::IMREAD_UNCHANGED);
        for(int i=0;i<(int)face_pos->size();i++){
            cv::resize(deco, deco, cv::Size(face_pos->at(i).size()/3), 0, 0, CV_INTER_LINEAR);
            Point center((face_pos->at(i).x + face_pos->at(i).width/9), (face_pos->at(i).y + face_pos->at(i).height/9*4));
            convertMatImage = AddImage(convertMatImage, deco, center);

            Point center2((face_pos->at(i).x + face_pos->at(i).width/9*6), (face_pos->at(i).y + face_pos->at(i).height/9*4));
            convertMatImage = AddImage(convertMatImage, deco, center2);
        }
        break;
    case blusher:
        deco = imread("../WONS/resource/blusher.png", cv::ImreadModes::IMREAD_UNCHANGED);
        cv::resize(deco, deco, cv::Size(30, 30), 0, 0, CV_INTER_LINEAR);
        for(int i=0;i<(int)face_pos->size();i++){
            cv::resize(deco, deco, cv::Size(face_pos->at(i).size()/3), 0, 0, CV_INTER_LINEAR);
            Point center((face_pos->at(i).x + face_pos->at(i).width/9), (face_pos->at(i).y + face_pos->at(i).height/9*4));
            convertMatImage = AddImage(convertMatImage, deco, center);

            Point center2((face_pos->at(i).x + face_pos->at(i).width/9*6), (face_pos->at(i).y + face_pos->at(i).height/9*4));
            convertMatImage = AddImage(convertMatImage, deco, center2);
        }
        break;
    }
    return convertMatImage.clone();
}

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
