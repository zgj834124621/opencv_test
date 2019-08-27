#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

Mat src, dst;
char input_title[] = "input image";
int main(int argv, char** argc) {

	/*
	读取彩色图像
	*/
	src = imread("H:/opencv_test/image/line.png");
	if (!src.data) {
		cout << "could not load image..." << endl;
		return -1;
	}
	namedWindow(input_title, CV_WINDOW_NORMAL);
	imshow(input_title, src);
	
	/*
	转换为灰度图像
	*/
	Mat gray_src;
	cvtColor(src, gray_src, CV_BGR2GRAY);//彩色图像变为灰度图像
	
	/*
	转换为二值图像
	*/
	Mat binImage;
	adaptiveThreshold(~gray_src, binImage, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);//~取反操作
	namedWindow("binary Image", CV_WINDOW_NORMAL);
	imshow("binary Image", binImage);
	
	/*
	定义结构元素
	*/
	//水平结构元素
	Mat hline = getStructuringElement(MORPH_RECT, Size(src.cols/16, 1), Point(-1, -1));
	//垂直结构元素
	Mat vline = getStructuringElement(MORPH_RECT, Size(1, src.rows / 16), Point(-1, -1));
	//矩形结构
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	
	/*
	形态学Ex
	*/
	Mat temp;
	//erode(binImage, temp, hline);//腐蚀Ex
	//dilate(temp, dst, hline);//膨胀Ex
	morphologyEx(binImage, dst, CV_MOP_OPEN,hline);

	/*
	对图像每个像素进行取反Ex
	*/
	bitwise_not(dst, dst);
	namedWindow("Final result", CV_WINDOW_NORMAL);
	imshow("Final result", dst);

	waitKey(0);
	return 0;
}