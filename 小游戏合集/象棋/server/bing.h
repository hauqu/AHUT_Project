#pragma once

#include"chess.h"
/*
“兵（卒）”在过河前每一回合只可以往前行走一步，
过河后，可以向左、向右或往前行进一步，但是永远不能往后方移动。

*/

class bing :public chess
{
	/*
		向前移动，一次一格
	*/
public:
	int line;


public:
	bing(bool player, int x, int y);
	~bing() {}
public:

	virtual bool move(int i, int j)
	{
		vector<point2>ps;
		if (player)//黑子
		{
			ps.push_back(point2(x, y + 1));

			if (y>=RedRiverCol)//过河
			{
				ps.push_back(point2(x - 1, y));
				ps.push_back(point2(x + 1, y));
			}
			for (int k = 0; k < ps.size(); k++)
			{
				if (ps[k].x == i && ps[k].y == j)
					return true;
			}
		}else //红子
		{
			ps.push_back(point2(x, y - 1));

			if (y <= BlackRiverCol)//过河
			{
				ps.push_back(point2(x - 1, y));
				ps.push_back(point2(x + 1, y));
			}
			for (int k = 0; k < ps.size(); k++)
			{
				if (ps[k].x == i && ps[k].y == j)
					return true;
			}
		}
		
		
		//一次一格
		return false;
	}

};

bing::bing(bool player, int x, int y)
{
	this->player = player;
	this->x = x;
	this->y = y;
	this->alive = true;
	if(player)
	{
		line = BlackRiverCol;
	}else 
	{
		line = RedRiverCol;
	}
	
}
