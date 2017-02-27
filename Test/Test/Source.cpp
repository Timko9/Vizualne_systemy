#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <iostream>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <string>
#include <stdio.h>


// ************* program, kde nacita obrazok a zobrazi ho ************/
/*
void main(void)
{
cv::Mat img = cv::imread("c:\\opencv\\foto\\Jessica.jpg", 1);
cv::imshow("show the image test", img);
cvWaitKey(8000);

}
*/


// *********** program, kde spojazdni kameru a zobrazi stream ****//////

using namespace cv;
using namespace std;

void nahraj() {
	int count = 1;
	//create matris to store image
	Mat image;
	//initialize capture
	VideoCapture cap;
	cap.open(0);
	//create window to show image
	namedWindow("window", 1);
	bool check = true;

	while (check == true) {
		//copy webcam stream to image
		cap >> image;
		//print image to screen
		imshow("window", image);
		waitKey(33);
		string name = "Img_" + std::to_string(count) + ".bmp";
		imwrite("C:\\OpenCV\\video\\" + name, image);
		++count;
		if (count > 600)
			check = false;
	}
}

void prehraj() {
	int count = 1;
	cv::Mat image;
	
	bool check = true;

	while (check == true) {
		string name = "Img_" + std::to_string(count) + ".bmp";
		image = imread("C:\\OpenCV\\video\\" + name, 1);
		imshow("show the image test", image);
		cvWaitKey(33);
		++count;
		if (count > 100)
			check = false;
	}
}

int main(void) {
	//nahraj();
	prehraj();
	return 0;
}