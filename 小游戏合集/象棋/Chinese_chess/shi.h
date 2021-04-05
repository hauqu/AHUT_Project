#pragma once

#include"chess.h"
/*
除了初始位置
其他一样jiang

*/

class shi :public chess
{
	/*
	在大本营移动，一次一格
	*/
public:
	int homeRow;
	int homeCol;

public:
	shi(bool player,int x,int y);
	~shi() {}
public:

	virtual bool move(int i, int j)
	{

		//一次一格，必须在固定区域
		if (i > homeRow + 1 || i < homeRow - 1)
			return false;
		if (j > homeCol + 1 || j < homeCol - 1)
			return false;
		if (i == x && j == y) return false;//需要告知自己能不能踩到自己
		//区域限定

		if (i == x)
		{
			if (j == y + 1 || j == y - 1)
			{
				return true;
			}
			else
				return false;
		}
		else if (j == y)
		{
			if (i == x + 1 || i == x - 1)
			{
				return true;
			}
			else
				return false;
		}
		return false;
		//一次一格
	}

};

shi::shi(bool player, int x, int y)
{
	this->player = player;
	this->x = x;
	this->y = y;
	this->alive = true;
	if (player)
	{
		homeRow = BlackHomeRow;
		homeCol = BlackHomeCol;
	}
	else
	{
		homeRow = RedHomeRow;
		homeCol = RedHomeCol;
	}
}
