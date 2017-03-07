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
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

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
		if (count > 100)
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

void optiflow() {
	// Obtain first image and set up two feature vectors
	cv::Mat image_prev, image_next;
	std::vector<cv::Point> features_prev, features_next;

	image_next = getImage();

	// Obtain initial set of features
	cv::goodFeaturesToTrack(image_next, // the image 
		features_next,   // the output detected features
		max_count,  // the maximum number of features 
		qlevel,     // quality level
		minDist     // min distance between two features
	);

	// Tracker is initialised and initial features are stored in features_next
	// Now iterate through rest of images
	for (;;)
	{
		image_prev = image_next.clone();
		feature_prev = features_next;
		image_next = getImage();  // Get next image

								  // Find position of feature in new image
		cv::calcOpticalFlowPyrLK(
			image_prev, image_next, // 2 consecutive images
			points_prev, // input point positions in first im
			points_next, // output point positions in the 2nd
			status,    // tracking success
			err      // tracking error
		);

		if (stopTracking()) break;
	}
}

int main(void) {
	//nahraj();
	//prehraj();
	optiflow();
	return 0;
}