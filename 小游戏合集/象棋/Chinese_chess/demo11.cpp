#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;
///////////////// cam face /////////////////////
void main()
{
	
	VideoCapture cap(2);
	Mat img;
	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	//加载模型
	if (faceCascade.empty())
	{
		cout << "XML file load fail" << endl;
	}

	

	
	while (true) {

		cap.read(img);
		vector<Rect>faces;
		faceCascade.detectMultiScale(img, faces, 1.1, 10);
		for (int i = 0; i < faces.size(); i++)
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 3);
		imshow("img", img);//显示视频
		//cvShowImage("imge",&img);
		waitKey(1000);//等待，决定每一帧停顿的时间

		//当视频显示完成后，由于没有图像读取，会给你一个错误。
	}
}