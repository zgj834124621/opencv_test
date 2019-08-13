#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argv, char** argc) {
	Mat src,dst;
	src = imread("H:/opencv_test/image/1.png");
	if (!src.data) {
		cout << "could not load image..." << endl;
		return -1;
	}
	char input_win[] = "input window";
	namedWindow("input_win", CV_WINDOW_AUTOSIZE);
	imshow("input_image", src);

	//contrast and brightness change
	int high = src.rows;
	int width = src.cols;
	dst = Mat::zeros(src.size(), src.type());
	float alpha = 1.2;
	float beta = 10;

	for (int row = 0; row < high; row++) {
		for (int col = 0; col < width; col++) {
			if (src.channels() == 3) {
				float b = src.at<Vec3b>(row, col)[0];//方括号里的数字表示第几通道；Vec3b表示使用迭代器进行
				float g = src.at<Vec3b>(row, col)[1];
				float r = src.at<Vec3b>(row, col)[2];

				dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b*alpha + beta);
				dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g*alpha + beta);
				dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r*alpha + beta);
			}
			if (src.channels() == 1) {
				float v = src.at<uchar>(row, col);

				dst.at<uchar>(row, col) = v;
			}
		}
	}

	char out_win[] = "contrast and brightness demo";
	namedWindow(out_win,CV_WINDOW_AUTOSIZE);
	imshow(out_win, dst);

	waitKey(0);
	return 0;
}