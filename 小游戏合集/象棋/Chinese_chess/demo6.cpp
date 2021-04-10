#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;
////////////////绘图和文字/////////////////////////////
int main()
{
	Mat img(512, 512, CV_8UC3, Scalar(64, 64, 64));//创建一个图像
	circle(img, Point(256, 256), 155, Scalar(58, 69, 25), FILLED);//画一个圆
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255),FILLED);
	//画一个矩形
	line(img, Point(10, 10), Point(300, 300),Scalar(255,255,0));
	//画一条线
	putText(img,"ni gai si",Point(200,200),FONT_HERSHEY_DUPLEX,2,Scalar(0,0,128),2);
	//画文本
	imshow("img", img);
	
	

	waitKey(100000);
	return 0;
}
