#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>


float w = 500;
float h = 320;
using namespace std;
using namespace cv;

////////////////////////翘曲图像,返回俯视图//////////////////////
int main()
{
	string path = "Resources/7.jpg";
	Mat img,imgWarp,matrix;
	img = imread(path);
	/*
	316,130,左上
	638,312右上
	193,388左下
	518,529右下
	
	
	*/

	Point2f scr[4] =
	{
		{316,130},
		{638,312},
		{193,340},
		{518,529}
	};//转换前的四点，矩形四角顺序
	for (int i = 0; i < 4; i++)
	{
		circle(img,scr[i],10, Scalar(0, 255, 0),FILLED);
	}
	Point2f dst[4] =
	{
		{0.0,0.0},
		{w,0},
		{0.0,h},
		{w,h}

	};//转换后的四点
	matrix = getPerspectiveTransform(scr, dst);//返回转换模式

	warpPerspective(img, imgWarp, matrix, Point(w, h));
	//返回转换后的图像，该函数完成将 普通视角改为俯视图
	imshow("imgWarp", imgWarp);
	imshow("img", img);
	//imshow("matrix", matrix);
	waitKey(100000);
	return 0;
}