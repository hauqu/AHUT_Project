#pragma once


#include"chess.h"

class che :public chess
{

	/*
		任意移动，走直线
	*/
public:


public:
	che(bool player, int x, int y);//初始化与shi相同
	~che() {}
public:

	virtual bool move(int i, int j)
	{
		if (x==i)
		{
			if (y != j) return true;
		}else if(y==j)
		{
			if (x != i) return true;
		}
		return false;
	}

};

che::che(bool player, int x, int y)
{

	this->player = player;
	this->x = x;
	this->y = y;
	this->alive = true;

}
