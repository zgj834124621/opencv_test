#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

Mat src, dst;
char input_title[] = "input image";
char output_title[] = "output image";
int element_size = 3;
int max_size = 21;
void CallBack_Demo(int, void*);

int main(int argv, char** argc) {
	
	src = imread("H:/opencv_test/image/1.png");
	if (!src.data) {
		cout << "could not load image..." << endl;
		return -1;
	}

	namedWindow(input_title, CV_WINDOW_AUTOSIZE);
	imshow(input_title, src);


	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	createTrackbar("Element size", output_title, &element_size, max_size, CallBack_Demo);
	CallBack_Demo(0, 0);
	

	waitKey(0);
	return 0;
}

void CallBack_Demo(int, void*) {
	int s = element_size * 2 + 1;
	Mat structureElement = getStructuringElement(MORPH_RECT, Size(s, s), Point(-1, -1));
	//dilate(src, dst, structureElement, Point(-1, -1), 1);//ÅòÕÍ
	erode(src, dst, structureElement, Point(-1, -1), 1);
	imshow(output_title, dst);
	return;
}