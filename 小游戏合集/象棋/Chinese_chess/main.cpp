#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>

#include<iostream>
#include"Map.h"
using namespace std;
using namespace cv;
void DrawLine(Mat img);
void DrawChess(Mat img);
int w = 9; int h = 9;
int k = 80;

int ox=100;int oy=100;
Map game;
Mat chessp[32];
Mat chessImg(w* k + 200, h* k + 200, CV_8UC3);
void loadImage();
MouseCallback ms;
void moveImage();

int main()
{
	
	
	DrawLine(chessImg);
	DrawChess(chessImg);

	imshow("game", chessImg);
	
	waitKey(0);
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