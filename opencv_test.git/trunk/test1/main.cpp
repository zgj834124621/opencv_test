#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<iostream>

using namespace std;
using namespace cv;
int main(int argc, char** argv) {
	Mat src = imread("H:/opencv_test/test1/1.png");
	if (src.empty()) {
		printf("could not load ..\n");
		return -1;
	}
	namedWindow("test opencv setup",CV_WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);

	
	Mat output_image;
	cvtColor(src,output_image,CV_BGR2HLS);
	namedWindow("output windows", CV_WINDOW_AUTOSIZE);
	imshow("output_windows",output_image);

	imwrite("H:/HLStest.png",output_image);

	waitKey(0);
	return 0;
}