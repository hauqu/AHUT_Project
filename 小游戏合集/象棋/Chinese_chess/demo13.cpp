#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>



using namespace std;
using namespace cv;

////////////////////////颜色检测--摄像头版本//////////////////////

int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;
VideoCapture cap(2);//摄像头具有id ，默认摄像头id为 0
int main()
{
	
	
	Mat img, imgGray, imgHSV, mask;
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Mmax", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);
	while (true) {

		cap.read(img);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);//生成HSV图像


		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);
		//从 imgHSV中取出lower 到 upper范围的颜色部分到 mask
		imshow("img", img);
		//imshow("imgGray", imgGray);
		//imshow("imgHSV", imgHSV);
		imshow("imgMask", mask);
		waitKey(100);

		
	}
	
	return 0;
}