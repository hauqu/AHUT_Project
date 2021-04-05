#pragma once

#include"chess.h"


class jiang :public chess
{
/*
	�ڴ�Ӫ�ƶ���һ��һ��

*/

public:
	int homeRow;
	int homeCol;

public:
	jiang(bool player);
	~jiang() {}
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


jiang::jiang(bool player)
{
	this->player = player;
	this->alive = true;
	if (player)
	{
		homeRow = BlackHomeRow;
		homeCol = BlackHomeCol;
		this->y = homeCol-1;
	}
	else
	{
		homeRow = RedHomeRow;
		homeCol = RedHomeCol;
		this->y = homeCol + 1;
	}
	this->x = homeRow;
	
}