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
		vector<point2>ps;
		if (player)//����
		{
			ps.push_back(point2(x, y + 1));

			if (y>=RedRiverCol)//����
			{
				ps.push_back(point2(x - 1, y));
				ps.push_back(point2(x + 1, y));
			}
			for (int k = 0; k < ps.size(); k++)
			{
				if (ps[k].x == i && ps[k].y == j)
					return true;
			}
		}else //����
		{
			ps.push_back(point2(x, y - 1));

			if (y <= BlackRiverCol)//����
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
		
		
		//һ��һ��
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
