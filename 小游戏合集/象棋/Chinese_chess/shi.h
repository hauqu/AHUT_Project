#pragma once

#include"chess.h"
/*
除了初始位置
其他一样jiang

*/

class shi :public chess
{
	/*
	在大本营移动，一次一格，斜着
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
		vector<point2>ps;
		//一次一格，必须在固定区域
		if (i > homeRow + 1 || i < homeRow - 1)
			return false;
		if (j > homeCol + 1 || j < homeCol - 1)
			return false;
		if (i == x && j == y) return false;//需要告知自己能不能踩到自己
		//区域限定
		ps.push_back(point2(x + 1, y + 1));
		ps.push_back(point2(x + 1, y - 1));
		ps.push_back(point2(x - 1, y + 1));
		ps.push_back(point2(x - 1, y - 1));
		for (int k = 0; k < ps.size(); k++)
		{
			if (ps[k].x == i && ps[k].y == j)
				return true;
		}
		//一次一格
		return false;
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
