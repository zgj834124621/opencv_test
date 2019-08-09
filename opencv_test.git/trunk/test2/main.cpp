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
	dst = Mat::zeros(src.size(), src.type());
	int cols = (src.cols-1) * src.channels();
	int offsetx = src.channels();
	int rows = src.rows;
	for (int row = 1; row < (rows - 1); row++) {
		uchar* output = dst.ptr<uchar>(row);
		const uchar * current = src.ptr<uchar>(row);
		const uchar * previous = src.ptr<uchar>(row-1);
		const uchar * next = src.ptr<uchar>(row+1);
		for (int col = offsetx; col < cols; col++) {
			output[col] = 5 * current[col] - (current[row - offsetx] + current[col + offsetx] + previous[col] + next[col]);
		}
	}

	namedWindow("contrast image demo", CV_WINDOW_AUTOSIZE);
	imshow("contrast image demo", dst);

	waitKey(0);
	return 0;
}