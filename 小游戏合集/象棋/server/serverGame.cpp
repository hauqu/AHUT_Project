/*
	作为游戏的服务端，处理输出输出，为方便调试绘制游戏内容
*/
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>

#include<iostream>
#include"Map.h"
using namespace std;
using namespace cv;
void DrawLine(Mat img);
void DrawChess(Mat img);
string WinName = "chess";
int w = 10; int h = 10;
int k = 80;


Map game;
Mat chessp[32];
Mat chessImg;
Mat tempImg;
void loadImage();

Point firstStep, secondStep;
bool first, second;

void on_MouseHandle(int event, int x, int y, int flags, void* param);

int main()
{
	chessImg =Mat(w * k + k, h * k, CV_8UC3);
	DrawLine(chessImg);
	DrawChess(chessImg);
	chessImg.copyTo(tempImg);
	namedWindow(WinName);
	setMouseCallback(WinName, on_MouseHandle, (void*)&tempImg);

	while (true)
	{
		
		if (first)
		{
			if (second)
			{
				bool is = game.moveChess(firstStep.x, firstStep.y, secondStep.x, secondStep.y);
				tempImg = Mat(w * k + k, h * k, CV_8UC3);
				DrawLine(tempImg);
				DrawChess(tempImg);
				if (is)
				{
					cout << "成功" << endl;
				}
				else
				{
					cout << "失败" << endl;
				}
				second = false;
				first = false;

			}


		}
			
		
		imshow(WinName, tempImg);
		if (waitKey(10) == 27)
			break;
	}
	

	std::cin.get();
	return 0;
}
void DrawLine(Mat img)
{
	for (int i = 1; i < w; i++)
	{
		line(img, Point(k * i  , k  ), Point(k * i  , (h / 2) * k  ), Scalar(0, 0, 0));
		line(img, Point(k * i  , (h / 2 + 1) * k  ), Point(k * i  , h * k  ), Scalar(0, 0, 0));
	}
	line(img, Point(k * (w - 1)  , (h / 2) * k  ), Point(k * (w - 1)  , (h / 2 + 1) * k  ), Scalar(0, 0, 0));
	line(img, Point(k  , (h / 2) * k  ), Point(k  , (h / 2 + 1) * k  ), Scalar(0, 0, 0));

	for (int i = 1; i <= h; i++)
	{
		line(img, Point(k  , k * i  ), Point((w - 1) * k  , k * i  ), Scalar(0, 0, 0));
	}

	line(img, Point(5 * k, 2 * k), Point(6 * k, 1 * k), Scalar(0, 0, 0));
	line(img, Point(5 * k, 2 * k), Point(4 * k, 1 * k), Scalar(0, 0, 0));

	line(img, Point(5 * k, 2 * k), Point(6 * k, k * 3), Scalar(0, 0, 0));
	line(img, Point(5 * k, 2 * k), Point(4 * k, k * 3), Scalar(0, 0, 0));
	
	line(img, Point(5 * k, 9 * k), Point(6 * k, 10 * k), Scalar(0, 0, 0));
	line(img, Point(5 * k, 9 * k), Point(4 * k, 10 * k), Scalar(0, 0, 0));

	line(img, Point(5 * k, 9 * k), Point(6 * k, k * 8), Scalar(0, 0, 0));
	line(img, Point(5 * k, 9 * k), Point(4 * k, k * 8), Scalar(0, 0, 0));

}

void DrawChess(Mat img)
{
	int x, y;
	for (int i = 1; i < 33; i++)
	{
		if (game.cs[i]->alive!=false)
		{
			x = game.cs[i]->x;
			y = game.cs[i]->y;
			circle(img, Point(x * k  , y * k  ), k / 2, Scalar(128, 128, 128), FILLED);
			if (game.cs[i]->player)
			{
				circle(img, Point(x * k  , y * k  ), k / 2 - 5, Scalar(0, 0, 0), FILLED);

			}
			else
			{
				circle(img, Point(x * k  , y * k  ), k / 2 - 5, Scalar(0, 0, 255), FILLED);
			}

			putText(img, game.csName[i], Point(x * k   - 40, y * k   + 10),
				FONT_HERSHEY_DUPLEX, 0.8, Scalar(255, 255, 255), 0.5);
		}

	}
}
void loadImage()
{
	for (size_t i = 0; i < 32; i++)
	{
		string path = "Resources/chess/" + to_string(i) + ".jpg";

	}
}

void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
	Mat& image = *(Mat*)param;
	Point step;
	switch (event)
	{

		if (x<k||y<k)
		{
			break;
		}
	case EVENT_MOUSEMOVE:
	{

		//cout << "(" << x << "," << y << ")" << endl;
	}
	break;
	// 左键按下消息
	case EVENT_LBUTTONDOWN:
	{
		//DrawLine(tempImg);
		//DrawChess(tempImg);
		//cout << "(" << x << "," << y << ")" << endl;

		step = Point((x   + k / 2) / k, (y   + k / 2) / k);
		cout << "(" << step.x << "," << step.y << ")-->" ;
		
		rectangle(tempImg, Rect(step.x * k   - k / 2, step.y * k   - k / 2, k, k), Scalar(0, 0, 255));
		imshow(WinName, tempImg);
	}
	break;
	//左键抬起消息
	case EVENT_LBUTTONUP:
	{
		step = Point((x   + k / 2) / k, (y   + k / 2) / k);
		if (!first)
		{
			firstStep = step;
			first = true;
			if (game.findChess(step.x,step.y)==-1)
			{
				first = false;
			}
			
		}
		else
		{
			secondStep = step;
			second = true;
		}

		if (second)
			cout << endl;

	}
	break;
	case EVENT_RBUTTONDOWN:
	{
		if (second)
		{
			second = false;
		}
		else if (first)
		{
			first = false;
		}
	}
	break;
	}
}