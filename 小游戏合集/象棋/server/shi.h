#pragma once

#include"chess.h"
/*
���˳�ʼλ��
����һ��jiang

*/

class shi :public chess
{
	/*
	�ڴ�Ӫ�ƶ���һ��һ��б��
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
		//һ��һ�񣬱����ڹ̶�����
		if (i > homeRow + 1 || i < homeRow - 1)
			return false;
		if (j > homeCol + 1 || j < homeCol - 1)
			return false;
		if (i == x && j == y) return false;//��Ҫ��֪�Լ��ܲ��ܲȵ��Լ�
		//�����޶�
		ps.push_back(point2(x + 1, y + 1));
		ps.push_back(point2(x + 1, y - 1));
		ps.push_back(point2(x - 1, y + 1));
		ps.push_back(point2(x - 1, y - 1));
		for (int k = 0; k < ps.size(); k++)
		{
			if (ps[k].x == i && ps[k].y == j)
				return true;
		}
		//һ��һ��
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
