#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argc, char ** argv) {

	Mat src;
	src = imread("H:/opencv_test/image/1.png");
	if (src.empty()) {
		cout << "could not load image..." << endl;
		return -1;
	}

	namedWindow("input",CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	//初始化Mat对象
	Mat dst;
	dst = Mat(src.size(), src.type());
	dst = Scalar(127, 0, 255);
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", dst);

	waitKey(0);
	return 0;
}