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
	//����һ���˲�Դ��
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
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[row - offsetx] + current[col + offsetx] + previous[col] + next[col]));//���ط�Χ�����api---saturat_cast<uchar>(),������ȷ��RGBֵ�ķ�Χ��0��255֮��
		}
	}
	*/

	//������������opencv api��filter2D()����
	double t = getTickCount();
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, 
		                             -1, 5, -1,
		                              0, -1, 0);//������ģ
	filter2D(src, dst, src.depth(), kernel);//src.depth()��ʾλͼ����ȣ�������32��24��8�ȡ� kernel��ʾ��ģ
	double timeconsume = (getTickCount() - t) / getTickFrequency();
	printf("time consume = %.2f\n", timeconsume);

	namedWindow("contrast image demo", CV_WINDOW_AUTOSIZE);
	imshow("contrast image demo", dst);

	waitKey(0);
	return 0;
}