#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

Mat src, dst;
char input_title[] = "input image";
int main(int argv, char** argc) {

	src = imread("H:/opencv_test/image/1.png");
	if (!src.data) {
		cout << "could not load image..." << endl;
		return -1;
	}

	//namedWindow(input_title, CV_WINDOW_AUTOSIZE);
	//imshow(input_title, src);

	waitKey(0);
	return 0;
}