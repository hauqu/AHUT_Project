/*
该文件 用于不带鼠标逻辑的测试，控制由客户端进行
包含网络服务
*/

#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>

#include<iostream>
#include"Map.h"
#include"Server.h"



int w = 10; int h = 10;
int k = 80;


using namespace cv;
Map game;

Mat chessImg;

string WinName = "chess";


void DrawLine(Mat img);
void DrawChess(Mat img);


int main()
{
	chessImg = Mat(w * k + k, h * k, CV_8UC3);
	DrawLine(chessImg);
	DrawChess(chessImg);
	namedWindow(WinName);
	Server mainServer = Server(12345);
	while (true)
	{
		if(mainServer.players.size()==2)
		{
			break;//由两个玩家，nice
		}
	}

	while (true)
	{

		imshow(WinName, chessImg);
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
		line(img, Point(k * i, k), Point(k * i, (h / 2) * k), Scalar(0, 0, 0));
		line(img, Point(k * i, (h / 2 + 1) * k), Point(k * i, h * k), Scalar(0, 0, 0));
	}
	line(img, Point(k * (w - 1), (h / 2) * k), Point(k * (w - 1), (h / 2 + 1) * k), Scalar(0, 0, 0));
	line(img, Point(k, (h / 2) * k), Point(k, (h / 2 + 1) * k), Scalar(0, 0, 0));

	for (int i = 1; i <= h; i++)
	{
		line(img, Point(k, k * i), Point((w - 1) * k, k * i), Scalar(0, 0, 0));
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
		if (game.cs[i]->alive != false)
		{
			x = game.cs[i]->x;
			y = game.cs[i]->y;
			circle(img, Point(x * k, y * k), k / 2, Scalar(128, 128, 128), FILLED);
			if (game.cs[i]->player)
			{
				circle(img, Point(x * k, y * k), k / 2 - 5, Scalar(0, 0, 0), FILLED);

			}
			else
			{
				circle(img, Point(x * k, y * k), k / 2 - 5, Scalar(0, 0, 255), FILLED);
			}

			putText(img, game.csName[i], Point(x * k - 40, y * k + 10),
				FONT_HERSHEY_DUPLEX, 0.8, Scalar(255, 255, 255), 0.5);
		}

	}
}

/*
void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
	Mat& image = *(Mat*)param;
	Point step;
	switch (event)
	{

		if (x < k || y < k)
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

		step = Point((x + k / 2) / k, (y + k / 2) / k);
		cout << "(" << step.x << "," << step.y << ")-->";

		rectangle(tempImg, Rect(step.x * k - k / 2, step.y * k - k / 2, k, k), Scalar(0, 0, 255));
		imshow(WinName, tempImg);
	}
	break;
	//左键抬起消息
	case EVENT_LBUTTONUP:
	{
		step = Point((x + k / 2) / k, (y + k / 2) / k);
		if (!first)
		{
			firstStep = step;
			first = true;
			if (game.findChess(step.x, step.y) == -1)
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
*/