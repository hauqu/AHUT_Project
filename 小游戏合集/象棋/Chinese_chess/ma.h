#pragma once


#include"chess.h"

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
