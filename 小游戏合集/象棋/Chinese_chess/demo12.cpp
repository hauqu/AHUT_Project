#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;
///////////////// find color /////////////////////

vector<vector<int>>myColors
{
	{0,0,0,180,255,46},//黑色
	{0,0,46,180,43,220},//灰色
	{0,0,221,180,30,255},//白色
	{0,43,46,10,255,255},//红色
	{11,43,46,25,255,255},//橙色
	{26,43,46,34,255,255},//黄色
	{35,43,46,77,255,255},//绿色
	{78,43,46,99,255,255},//青色
	{100,43,46,124,255,255},//蓝色
	{125,43,46,155,255,255}//紫色

};
vector<Scalar>myColorValues
{
	{255,0,255},//for 紫色
	{0,255,0}//for 绿色
};


void findColor(Mat img)
{
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);//生成HSV图像

	for (int i = 0; i < myColors.size(); i++)
	{
		Mat mask;
		Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
		Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
		inRange(imgHSV, lower, upper, mask);
		imshow(to_string(i), mask);
	}
	
	
	//从 imgHSV中取出lower 到 upper范围的颜色部分到 mask
}
void main()
{

	VideoCapture cap(2);
	Mat img;
	


	while (true) {

		cap.read(img);
		findColor(img);
		imshow("img", img);//显示视频
		//cvShowImage("imge",&img);
		waitKey(1);//等待，决定每一帧停顿的时间

		//当视频显示完成后，由于没有图像读取，会给你一个错误。
	}
}