#pragma once

#include"chess.h"

class xiang :public chess
{

	/*
	
	�ڼ���ս���ƶ�������
	*/
public:

	int ableColL;
	int ableColH;

public:
	xiang(bool player, int x, int y);//��ʼ����shi��ͬ
	~xiang() {}
public:

	virtual bool move(int i, int j)
	{
		if(i<=ableColH&&j>=ableColL)//��ս��
		{
			if (i==x+2)
			{
				if(j==y+2)
				{
					return true;
				}
				else if(j==y-2)
				{
					return true;
				}
				return false;
			}
			else if(j==y-2)
			{
				if (i == x + 2)
				{
					return true;
				}
				else if (i == x - 2)
				{
					return true;
				}
				return false;
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
		ableColL = 0;
		ableColH = BlackRiverCol;
	}
	else
	{
		ableColL = RedRiverCol;
		ableColH = 9;
	}
}
