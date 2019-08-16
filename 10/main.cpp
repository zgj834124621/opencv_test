#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argv, char** argc) {
	Mat src, dst,gblur;
	char input_title[] = "input image";
	char medianBlur_title[] = "medianBlur image";
	char bilateralFilter_title[] = "bilateralFilter image";
	char gaussianBlur_title[] = "gaussianBlur image";
	src = imread("H:/opencv_test/image/1.png");
	if (!src.data) {
		cout << "could not load image..." << endl;
		return -1;
	}
	namedWindow(input_title, CV_WINDOW_AUTOSIZE);
	imshow(input_title, src);
	/*
	//��ֵ�˲�
	medianBlur(src, dst, 3);
	namedWindow(medianBlur_title, CV_WINDOW_AUTOSIZE);
	imshow(medianBlur_title, dst);
	*/
	//˫���˲�
	bilateralFilter(src, dst, 15, 100, 5);//d-�������͵ı�������ʾ���������ֱ��
	                                      //sigmaColor-�������͵ı�������ʾ��ɫ�ռ��еĹ�����sigma
	                                      //sigmaSpace-�������͵ı�������ʾ����ռ�Ĺ�����sigma
	namedWindow(bilateralFilter_title, CV_WINDOW_AUTOSIZE);
	imshow(bilateralFilter_title, dst);

	//��˹�˲�
	GaussianBlur(src, gblur, Size(15, 15), 3, 3);
	namedWindow(gaussianBlur_title, CV_WINDOW_AUTOSIZE);
	imshow(gaussianBlur_title, gblur);

	Mat resultImage;
	Mat keenel = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(dst, resultImage, -1, keenel, Point(-1, -1), 0);
	imshow("Final image", resultImage);

	waitKey(0);
	return 0;
}