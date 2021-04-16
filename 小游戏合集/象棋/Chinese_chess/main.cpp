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
int w = 9; int h = 9;
int k = 80;

int ox=100;int oy=100;
Map game;
Mat chessp[32];
Mat chessImg(w* k + 200, h* k + 200, CV_8UC3);
Mat tempImg;
void loadImage();

Point firstStep,secondStep;
bool first, second;

void on_MouseHandle(int event, int x, int y, int flags, void* param);

int main()
{
	DrawLine(chessImg);
	DrawChess(chessImg);
	chessImg.copyTo(tempImg);
	namedWindow(WinName);
	setMouseCallback(WinName, on_MouseHandle, (void*)&tempImg);

	while (true)
	{
		if (first)
		{
			int ci = game.findChess(firstStep.x, firstStep.y);
			if (ci!=-1)
			{
				if(second)
				{
					int cj =game.findChess(secondStep.x,secondStep.y);
					if(game.cs[ci]->move(secondStep.x, secondStep.y))
					{
						game.cs[ci]->x = secondStep.x;
						game.cs[ci]->y = secondStep.y;
						first = false;
						second = false;

						tempImg = Mat(w * k + 200, h * k + 200, CV_8UC3);

						DrawLine(tempImg);
						DrawChess(tempImg);
						
						
					}
				}
			}
		}
		imshow(WinName, tempImg);
		if(waitKey(10)==27)
			break;
	}
	

	
	
	
	std::cin.get();
	return 0;
}
void DrawLine(Mat img)
{
	for (int i = 0; i < w; i++)
	{
		line(img,Point( k * i+ox, 0+oy),Point( k * i + ox, (h /2)* k+oy),Scalar(0,0,0));
		line(img, Point(k * i + ox, (h / 2 + 1) * k + oy), Point(k * i + ox, h * k + oy), Scalar(0, 0, 0));
	}
	line(img, Point(k * (w - 1) + ox, (h / 2) * k + oy), Point(k * (w - 1) + ox, (h / 2 + 1) * k + oy), Scalar(0, 0, 0));
	line(img, Point(0 + ox, (h / 2) * k + oy) , Point(0 + ox, (h / 2 + 1) * k + oy), Scalar(0, 0, 0));
	
	for (int i = 0; i <= h; i++)
	{
		line(img, Point(0 + ox, k * i + oy), Point((w - 1) * k + ox, k * i + oy), Scalar(0, 0, 0));
	}

	line(img, Point(4 * k + ox, k + oy),Point(5 * k + ox, 0 + oy), Scalar(0, 0, 0));
	line(img, Point(4 * k + ox, k + oy),Point(3 * k + ox, 0 + oy), Scalar(0, 0, 0));

	line(img, Point(4 * k + ox, k + oy), Point(5 * k + ox, k * 2 + oy), Scalar(0, 0, 0));
	line(img, Point(4 * k + ox, k + oy), Point(3 * k + ox, k * 2 + oy), Scalar(0, 0, 0));

	line(img, Point(4 * k + ox, 8*k + oy), Point(5 * k + ox, k * 7 + oy), Scalar(0, 0, 0));
	line(img, Point(4 * k + ox, 8*k + oy), Point(3 * k + ox, k * 7 + oy), Scalar(0, 0, 0));

	line(img, Point(4 * k + ox, 8 * k + oy), Point(5 * k + ox, k * 9 + oy), Scalar(0, 0, 0));
	line(img, Point(4 * k + ox, 8 * k + oy), Point(3 * k + ox, k * 9 + oy), Scalar(0, 0, 0));

	
}

void DrawChess(Mat img)
{
	int x, y;
	for (int i = 0; i < 32; i++)
	{
		if(game.cs[i]!=nullptr)
		{
			x = game.cs[i]->x;
			y = game.cs[i]->y;
			circle(img, Point(x * k + ox, y * k + oy), k / 2, Scalar(128, 128, 128), FILLED);
			if(game.cs[i]->player)
			{
				circle(img, Point(x * k + ox, y * k + oy), k / 2 - 5, Scalar(0, 0, 0),FILLED);
				
			}else 
			{
				circle(img, Point(x * k + ox, y * k + oy), k / 2 - 5, Scalar(0, 0, 255), FILLED);
			}
			
			putText(img, game.csName[i], Point(x * k + ox-40, y * k + oy+10),
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
	case EVENT_MOUSEMOVE:
	{

		//cout << "(" << x << "," << y << ")" << endl;
	}
	break;
	// 左键按下消息
	case EVENT_LBUTTONDOWN:
	{
		DrawLine(tempImg);
		DrawChess(tempImg);
		//cout << "(" << x << "," << y << ")" << endl;
		
		step = Point((x-ox+k/2)/k, (y-oy+k/2)/k);
		cout << "(" << step.x << "," << step.y << ")" << endl;
		rectangle(tempImg, Rect(step.x*k+ox-k/2, step.y*k+oy-k/2, k, k), Scalar(0, 0, 255));
		imshow(WinName, tempImg);
	}
	break;
	//左键抬起消息
	case EVENT_LBUTTONUP:
	{
		step = Point((x - ox + k / 2) / k, (y - oy + k / 2) / k);
		if (!first)
		{
			firstStep = step;
			first = true;
		}else
		{
			secondStep = step;
			second = true;
		}
	}
	break;
	case EVENT_RBUTTONDOWN:
	{
		if (second)
		{
			second = false;
		}else if(first)
		{
			first = false;
		}
	}
	break;
	}
}