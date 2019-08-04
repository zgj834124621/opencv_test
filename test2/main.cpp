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
	//方法一：滤波源码
	/*
	int cols = (src.cols-1) * src.channels();
	int offsetx = src.channels();
	int rows = src.rows;
	dst = Mat::zeros(src.size(), src.type());
	for (int row = 1; row < (rows - 1); row++) {
		uchar* output = dst.ptr<uchar>(row);
		const uchar * current = src.ptr<uchar>(row);
		const uchar * previous = src.ptr<uchar>(row-1);
		const uchar * next = src.ptr<uchar>(row+1);
		for (int col = offsetx; col < cols; col++) {
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[row - offsetx] + current[col + offsetx] + previous[col] + next[col]));//像素范围处理的api---saturat_cast<uchar>(),它可以确保RGB值的范围在0～255之间
		}
	}
	*/

	//方法二：调用opencv api，filter2D()功能
	double t = getTickCount();
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, 
		                             -1, 5, -1,
		                              0, -1, 0);//定义掩模
	filter2D(src, dst, src.depth(), kernel);//src.depth()表示位图的深度，例如有32，24，8等。 kernel表示掩模
	double timeconsume = (getTickCount() - t) / getTickFrequency();
	printf("time consume = %.2f\n", timeconsume);

	namedWindow("contrast image demo", CV_WINDOW_AUTOSIZE);
	imshow("contrast image demo", dst);

	waitKey(0);
	return 0;
}