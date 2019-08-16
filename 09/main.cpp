#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argv, char** argc) {
	Mat src, dst,gblur;
	src = imread("H:/opencv_test/image/1.png");
	if (!src.data) {
		cout << "could not load image..." << endl;
		return -1;
	}
	char input_title[] = "input image";
	char output_title1[] = "blur image";
	char output_title2[] = "Gaussian blur image";

	namedWindow(input_title, CV_WINDOW_AUTOSIZE);
	namedWindow(output_title1, CV_WINDOW_AUTOSIZE);
	namedWindow(output_title2, CV_WINDOW_AUTOSIZE);
	imshow(input_title, src);

	blur(src, dst, Size(3, 3), Point(-1, -1));
	imshow(output_title1, dst);

	GaussianBlur(src, gblur, Size(5, 5), 11, 11);
	imshow(output_title2, gblur);

	waitKey(0);
	return 0;
}