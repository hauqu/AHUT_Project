#pragma once


#include"chess.h"

class ma :public chess
{

	/*
		任意移动，走日
	*/
public:


public:
	ma(bool player, int x, int y);//初始化与shi相同
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
