#pragma once

#include"chess.h"
/*
���˳�ʼλ��
����һ��jiang

*/

class shi :public chess
{
	/*
	�ڴ�Ӫ�ƶ���һ��һ��
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

		//һ��һ�񣬱����ڹ̶�����
		if (i > homeRow + 1 || i < homeRow - 1)
			return false;
		if (j > homeCol + 1 || j < homeCol - 1)
			return false;
		if (i == x && j == y) return false;//��Ҫ��֪�Լ��ܲ��ܲȵ��Լ�
		//�����޶�

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
		//һ��һ��
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
