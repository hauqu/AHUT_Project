#pragma once


#include"chess.h"
using namespace std;
class ma :public chess
{

	/*
		�����ƶ�������
	*/
public:


public:
	ma(bool player, int x, int y);//��ʼ����shi��ͬ
	~ma() {}
public:

	virtual bool move(int i, int j)
	{
		//���ɺϷ���
		vector<point2>ps;

		ps.push_back(point2(x + 1, y + 2));
		ps.push_back(point2(x + 1, y - 2));
		ps.push_back(point2(x - 1, y + 2));
		ps.push_back(point2(x - 1, y - 2));
		ps.push_back(point2(x + 2, y + 1));
		ps.push_back(point2(x + 2, y - 1));
		ps.push_back(point2(x - 2, y + 1));
		ps.push_back(point2(x - 2, y - 1));
		for (int i = 0; i < ps.size(); i++)
		{
			if (ps[i].x == i && ps[i].y == j)
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
