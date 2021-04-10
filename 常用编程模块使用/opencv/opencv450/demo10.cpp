#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/objdetect.hpp>

#include<iostream>
#include<vector>
using namespace std;
using namespace cv;

//////////////////人脸识别//////////////////
string path = "Resources/faces.png";
int main()
{
	Mat img = imread(path);

	
	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	//加载模型
	if(faceCascade.empty())
	{
		cout << "XML file load fail" << endl;
	}
	
	vector<Rect>faces;
	
	faceCascade.detectMultiScale(img,faces,1.1,10);
	for (int i = 0; i < faces.size(); i++)
	
	rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 3);
	
	
	imshow("img", img);
	waitKey(100000);


	return 0;

}