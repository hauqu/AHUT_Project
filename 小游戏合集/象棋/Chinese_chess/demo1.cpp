#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;
///////////////// images/////////////////////
void main()
{
	string path = "Resources/img.jpg";//加载路径
	Mat img = imread(path);//读取图片
	
	imshow("img", img);//显示图片
		//cvShowImage("imge",&img);
	waitKey(1000);//等待
		while (true)
		{

		}
	
}