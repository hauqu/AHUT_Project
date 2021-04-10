#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;
///////////////// video/////////////////////
void main()
{
	string path = "Resources/video.mp4";//加载路径
	VideoCapture cap(path);
	Mat img;
	
	while (true) {
		
		cap.read(img);
		imshow("img", img);//显示视频
		//cvShowImage("imge",&img);
		waitKey(20);//等待，决定每一帧停顿的时间

		//当视频显示完成后，由于没有图像读取，会给你一个错误。
	}
}