#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;
////////////////调整大小，剪裁/////////////////////////////
int main()
{
	string path = "Resources/man.jpg";
	Mat img = imread(path);
	Mat imgResize ,imgCro;//缩放，剪裁
	cout << img.size()<<endl;
	
	//resize(img, imgResize,Size(240,320));//缩放到像素
	resize(img, imgResize, Size(), 0.5, 0.5);//进行缩放比例
	Rect r(100, 50, 250, 300);//左上点和 长宽
	
	imgCro = img(r);//将 r 部分剪裁

	imshow("man", img);
	imshow("reisze", imgResize);
	imshow("cro", imgCro);

	waitKey(100000);
	return 0;
}
