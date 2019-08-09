#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace cv;

int main(int argc, char ** argv) {

	Mat src, dst;
	src = imread("H:/opencv_test/image/1.png");
	if (!src.data) {
		return -1;
	}

	namedWindow("input_image", CV_WINDOW_AUTOSIZE);
	imshow("input_image", src);

	waitKey(0);
	return 0;
}