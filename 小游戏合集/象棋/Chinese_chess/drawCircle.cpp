#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

/*
点击鼠标绘制圆

*/

int r = 1;//半径
Mat img(640, 640, CV_8UC3),tempImg;
string WindoswName = "画布";
bool save;//确定是否保存到img



int main()
{
	img = Scalar::all(0);//黑色
	img.copyTo(tempImg);

	while (true)
	{

	}
	return 0;
}
