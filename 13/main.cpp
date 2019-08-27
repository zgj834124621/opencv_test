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
	��ȡ��ɫͼ��
	*/
	src = imread("H:/opencv_test/image/line.png");
	if (!src.data) {
		cout << "could not load image..." << endl;
		return -1;
	}
	namedWindow(input_title, CV_WINDOW_NORMAL);
	imshow(input_title, src);
	
	/*
	ת��Ϊ�Ҷ�ͼ��
	*/
	Mat gray_src;
	cvtColor(src, gray_src, CV_BGR2GRAY);//��ɫͼ���Ϊ�Ҷ�ͼ��
	
	/*
	ת��Ϊ��ֵͼ��
	*/
	Mat binImage;
	adaptiveThreshold(~gray_src, binImage, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);//~ȡ������
	namedWindow("binary Image", CV_WINDOW_NORMAL);
	imshow("binary Image", binImage);
	
	/*
	����ṹԪ��
	*/
	//ˮƽ�ṹԪ��
	Mat hline = getStructuringElement(MORPH_RECT, Size(src.cols/16, 1), Point(-1, -1));
	//��ֱ�ṹԪ��
	Mat vline = getStructuringElement(MORPH_RECT, Size(1, src.rows / 16), Point(-1, -1));
	//���νṹ
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	
	/*
	��̬ѧEx
	*/
	Mat temp;
	//erode(binImage, temp, hline);//��ʴEx
	//dilate(temp, dst, hline);//����Ex
	morphologyEx(binImage, dst, CV_MOP_OPEN,hline);

	/*
	��ͼ��ÿ�����ؽ���ȡ��Ex
	*/
	bitwise_not(dst, dst);
	namedWindow("Final result", CV_WINDOW_NORMAL);
	imshow("Final result", dst);

	waitKey(0);
	return 0;
}