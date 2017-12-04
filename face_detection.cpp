#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

#define useMouse "Mouse Event"
#define nonMouse "Non MouseEvent"
#define img_name "test_image.jpg"
int size = 10;

void on_change(int pos,void* param){
	//cout << "size :: " << pos << endl;
}

void onMouseEvent(int event, int x, int y, int flags, void* dstImage){
	
	Mat mouseImage = *(Mat*)dstImage;
	Mat tempImage = mouseImage.clone();
	
	createTrackbar("size", useMouse, &size, 255, on_change, (void*)&tempImage);	
	
	if(event != CV_EVENT_LBUTTONDOWN){
		//cout << "size :: " << size << endl;
		Rect unClickedRect(x-(size/2), y-(size/2), size,size);
		rectangle(tempImage, unClickedRect, Scalar(255,0,0),1);	
		imshow(useMouse, tempImage);	
	}
	
	else if(event == CV_EVENT_LBUTTONDOWN) {
		cout << Point(x,y) << endl;
		Mat tempImage = *(Mat*)dstImage;
		Rect clickedRect(x-(size/2), y-(size/2), size,size);

		Mat mask = getStructuringElement(MORPH_RECT, Size(3,3), Point(1,1));
			
		dilate(tempImage(clickedRect), mouseImage(clickedRect), mask, Point(-1,-1), 3);
		erode(tempImage(clickedRect), mouseImage(clickedRect), mask, Point(-1,-1), 3);
		medianBlur(tempImage(clickedRect), mouseImage(clickedRect), 5);
		imshow(useMouse, mouseImage);
	}
}

void face_detect(Mat* srcImage, Mat* cascadedImage, Mat* faceRoi){
	String face_cascade = "haarcascade_frontalface_alt.xml";
	String eye_cascade = "haarcascade_eye.xml";
	
	
	CascadeClassifier face;
	CascadeClassifier eye;
	
	if(srcImage->data == NULL){
		cout << img_name << "no image" <<endl;
		return ;
	}
	
	if(!face.load(face_cascade) || !eye.load(eye_cascade)){
		cout << "Cascade파일이 없습니다" << endl;
		return ;
	}
	
	Mat gray;
	cvtColor(*srcImage, gray, CV_RGB2GRAY);
	
	vector<Rect> face_pos;
	face.detectMultiScale(gray, face_pos, 1.1,3,0 | CV_HAAR_SCALE_IMAGE, Size(10,10));
	
	for(int i=0; i<(int)face_pos.size(); i++){
		rectangle(*cascadedImage, face_pos[i], Scalar(0,255,0),2);
	}
	
	for(int i=0; i<(int)face_pos.size(); i++){
		vector<Rect> eye_pos;
		
		Mat roi = gray(face_pos[i]);
		eye.detectMultiScale(roi, eye_pos, 1.1,3,0 | CV_HAAR_SCALE_IMAGE, Size(10,10));
		
		for(int j=0; j<(int)eye_pos.size(); j++){
			Point center(face_pos[i].x + eye_pos[j].x + (eye_pos[j].width / 2), face_pos[i].y + eye_pos[j].y + (eye_pos[j].height / 2));
			int radius = cvRound((eye_pos[j].width + eye_pos[j].height) * 0.2);
			circle(*cascadedImage, center, radius, Scalar(0,0,255),2);
		}
	}
	*faceRoi = gray(face_pos[0]);
}

int main(){
	
	Mat srcImage = imread(img_name);
	Mat cascadedImage, faceRoi;
	cascadedImage = srcImage.clone();
	face_detect(&srcImage, &cascadedImage, &faceRoi);
	imshow("src", srcImage);
	imshow("cascaded", cascadedImage);
	imshow("roi", faceRoi);
	imshow(useMouse, srcImage);
	
	setMouseCallback(useMouse, onMouseEvent, (void*)&srcImage);
	
	//Mat bilateral;
	//bilateralFilter(filtered_img, bilateral, -1,10,10);
	
	//imshow("filter", filtered_img);

	if(cvWaitKey() == 'q')
		return 0;
}
