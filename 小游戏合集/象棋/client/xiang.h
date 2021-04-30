#pragma once

#include"chess.h"

class xiang :public chess
{

	/*
	
	在己方战场移动，走田
	*/
public:

	int ableColL;
	int ableColH;

public:
	xiang(bool player, int x, int y);//初始化与shi相同
	~xiang() {}
public:

	virtual bool move(int i, int j)
	{

		if(i<=ableColH&&j>=ableColL)//本战场
		{
			vector<point2>ps;
			ps.push_back(point2(x + 2, y + 2));
			ps.push_back(point2(x + 2, y - 2));
			ps.push_back(point2(x - 2, y + 2));
			ps.push_back(point2(x - 2, y - 2));
			for (int k = 0; k < ps.size(); k++)
			{
				if (ps[k].x == i && ps[k].y == j)
					return true;
			}
			
		}

		return false;
		
	}

};

xiang::xiang(bool player, int x, int y)
{
	
	this->player = player;
	this->x = x;
	this->y = y;
	this->alive = true;
	if (player)
	{
		ableColL = 1;
		ableColH = BlackRiverCol;
	}
	else
	{
		ableColL = RedRiverCol;
		ableColH = 10;
	}
}
