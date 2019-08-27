#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

Mat src, dst;
char input_title[] = "input image";
int main(int argv, char** argc) {

	src = imread("H:/opencv_test/image/cat.png");
	if (!src.data) { 
		cout << "could not load image..." << endl;
		return -1;
	}

	namedWindow(input_title, CV_WINDOW_NORMAL);
	imshow(input_title, src);
	char output_title[] = "morphology demo";
	namedWindow(output_title, CV_WINDOW_NORMAL);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(11, 11), Point(-1, -1));
	morphologyEx( src, dst, CV_MOP_GRADIENT, kernel);
	imshow(output_title,dst);

	waitKey(0);
	return 0;
}