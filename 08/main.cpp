#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;
Mat bgImage;
const char* drowdemo_win = "drow shapes and text demo";
void MyLines();
void MyRectangle();
void MyEllipse();
void MyCircle();
void MyPolygon();
void RandomLineDemo();


int main(int argv, char** argc) {
	bgImage = imread("H:/opencv_test/image/1.png");
	if (!bgImage.data) {
		cout << "could not load bgimage..." << endl;
		return -1;
	}
	//MyLines();
	//MyRectangle();
	//MyEllipse();
	//MyCircle();
	//MyPolygon();

	//putText(bgImage, "hello world", Point(300, 300), CV_FONT_HERSHEY_COMPLEX, 1.0, Scalar(12, 23, 200), 2, 8);
	RandomLineDemo();
	//namedWindow(drowdemo_win, CV_WINDOW_AUTOSIZE);
	//imshow(drowdemo_win, bgImage);

	

	waitKey(0);
	return 0;
}
//绘制直线
void MyLines() {
	Point p1 = Point(20, 30);
	Point p2;
	p2.x = 400;
	p2.y = 400;
	Scalar color = Scalar(0, 0, 255);
	line(bgImage, p1, p2, color, LINE_8);
}
//绘制长方形
void MyRectangle() {
	Rect rect = Rect(150, 100, 600, 670);
	Scalar color = Scalar(255, 0, 0);
	rectangle(bgImage, rect, color, 2, LINE_8);
}
//绘制椭圆
void MyEllipse() {
	Scalar color = Scalar(0, 255, 0);
	ellipse(bgImage, Point(bgImage.cols / 2, bgImage.rows / 2), Size(bgImage.cols / 4, bgImage.rows / 8),0,0,360,color,2,LINE_8);//画椭圆
}
//绘制圆形
void MyCircle() {
	Scalar color = Scalar(0, 255, 255);
	Point center = Point(bgImage.cols / 2, bgImage.rows / 2);
	circle(bgImage, center, 100, color, 2, 8);//画圆
}

//绘制多边形
void MyPolygon() {
	//定义一个二维数组，形成一个封闭区域
	Point pts[1][5];
	pts[0][0] = Point(100, 100);
	pts[0][1] = Point(100, 200);
	pts[0][2] = Point(200, 200);
	pts[0][3] = Point(200, 100);
	pts[0][4] = Point(100, 100);

	const Point* ppts[] = { pts[0] };
	int npt[] = { 5 };//数组个数
	Scalar color = Scalar(255, 12, 255);

	fillPoly(bgImage, ppts, npt,1,color, 8); //画填充
}

//绘制随机直线
void RandomLineDemo() {
	RNG rng(12345);//cv::RNG生成高斯随机数gaussian(double sigma)
	Point pt1;
	Point pt2;
	Mat bg = Mat::zeros(bgImage.size(), bgImage.type());
	namedWindow("random line demo", CV_WINDOW_AUTOSIZE);
	for (int i = 0; i < 100000; i++) {
		pt1.x = rng.uniform(0, bgImage.cols);//生成正态分布随机数uniform(int a,int b)
		pt2.x = rng.uniform(0, bgImage.cols);
		pt1.y = rng.uniform(0, bgImage.rows);
		pt2.y = rng.uniform(0, bgImage.rows);
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		//检测按键超过50ms时，退出循环
		if (waitKey(50) > 0) {
			break;
		}
		line(bg, pt1, pt2, color, 1, 8);
		imshow("random line demo", bg);
	}
}