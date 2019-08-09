#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argv, char** argc) {
	Mat src,gray_src;
	src = imread("H:/opencv_test/image/1.png");
	if (!src.data) {
		cout << "could not load image..." << endl;
		return -1;
	}

	namedWindow("input_image", CV_WINDOW_AUTOSIZE);
	imshow("input_image", src);
	cvtColor(src, gray_src, CV_BGR2GRAY);
	int height = gray_src.rows;
	int width = gray_src.cols;


	waitKey(0);
	return 0;
}