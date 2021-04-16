#pragma once


#include"chess.h"
using namespace std;
class ma :public chess
{

	/*
		任意移动，走日
	*/
public:


public:
	ma(bool player, int x, int y);//初始化与shi相同
	~ma() {}
public:

	virtual bool move(int i, int j)
	{
		//生成合法点
		vector<point2>ps;

		ps.push_back(point2(x + 1, y + 2));
		ps.push_back(point2(x + 1, y - 2));
		ps.push_back(point2(x - 1, y + 2));
		ps.push_back(point2(x - 1, y - 2));
		ps.push_back(point2(x + 2, y + 1));
		ps.push_back(point2(x + 2, y - 1));
		ps.push_back(point2(x - 2, y + 1));
		ps.push_back(point2(x - 2, y - 1));
		for (int k= 0; k < ps.size(); k++)
		{
			if (ps[k].x == i && ps[k].y == j)
				return true;
		}
		return false;
	}

};

ma::ma(bool player, int x, int y)
{

	this->player = player;
	this->x = x;
	this->y = y;
	this->alive = true;
	
}
