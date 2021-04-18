#pragma once

#include"chess.h"
/*
�������䣩���ڹ���ǰÿһ�غ�ֻ������ǰ����һ����
���Ӻ󣬿����������һ���ǰ�н�һ����������Զ���������ƶ���

*/

class bing :public chess
{
	/*
		��ǰ�ƶ���һ��һ��
	*/
public:
	int line;


public:
	bing(bool player, int x, int y);
	~bing() {}
public:

	virtual bool move(int i, int j)
	{
		if(player)//�ڷ�
		{
			if(y<RedRiverCol)//δ����
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
		}else//�췽
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
			}//δ����
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
