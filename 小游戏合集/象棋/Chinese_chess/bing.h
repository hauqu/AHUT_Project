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
		if(player)//黑方
		{
			if(y<RedRiverCol)//未过河
			{
				if(x==i)
				{
					if (y == j - 1)
					{
						return true;
					}
					else return false;
				}else
				{
					return false;
				}
			}else
			{
				if (x == i)
				{
					if (y == j - 1)
					{
						return true;
					}
					return false;
				}else if(y==j)
				{
					if (x == i - 1 || x == i + 1)
					{
						return true;
					}return false;
				}
				return false;
			}
		}else//红方
		{
			if (y > BlackRiverCol)
			{
				if (x == i)
				{
					if (y == j + 1)
					{
						return true;
					}
					else return false;
				}
				else
				{
					return false;
				}
			}//未过河
			else
			{
				if (x == i)
				{
					if (y == j + 1)
					{
						return true;
					}
					else return false;
				}
				else if (y == j)
				{
					if (x == i - 1 || x == i + 1)
					{
						return true;
					}
					else return false;
				} return false;
			}
		}
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
