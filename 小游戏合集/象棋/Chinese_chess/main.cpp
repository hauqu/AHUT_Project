#include<graphics.h>
#include<iostream>
#include<string>
#include"Map.h"
using namespace std;
void DrawLine();
void DrawChess();
int w = 9; int h = 9;
int k = 80;
Map game;
IMAGE chessp[32];
void loadImage();
int main()
{
	initgraph(w*k+200, h*k+200);
	setorigin(100, 100);
	setbkcolor(RGB(128, 128, 64));
	cleardevice();


	DrawLine();
	DrawChess();
	std::cin.get();
	return 0;
}
void DrawLine()
{
	for (int i = 0; i < w; i++)
	{
		line(k * i, 0, k * i, (h /2)* k);
		line(k * i, (h/2+1) * k, k * i, h * k);
	}
	line(k *(w-1), (h / 2) * k, k * (w-1), (h / 2+1)*k);
	line(0, (h / 2) * k, 0, (h / 2 + 1) * k);
	for (int i = 0; i <= h; i++)
	{
		line(0, k * i, (w-1) * k,k*i);
	}

	line(4 * k, k, 5 * k, 0);
	line(4 * k, k, 3 * k, 0);

	line(4 * k, k, 5 * k, k * 2);
	line(4 * k, k, 3 * k, k * 2);

	line(4 * k, 8 * k, 5 * k, k * 7);
	line(4 * k, 8 * k, 3 * k, k * 7);

	line(4 * k, 8*k, 5 * k, k * 9);
	line(4 * k, 8*k, 3 * k, k * 9);


}

void DrawChess()
{
	

	int x; int y;
	for (int i = 0; i < 32; i++)
	{
		if (game.cs[i] != nullptr)
		{
			x = game.cs[i]->x*k;
			y = game.cs[i]->y*k;
			if (game.cs[i]->player)
				setfillcolor(BLACK);
			else
				setfillcolor(RED);
			fillcircle(x, y, k / 2);
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