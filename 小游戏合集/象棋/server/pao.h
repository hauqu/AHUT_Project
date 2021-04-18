
#pragma once


#include"chess.h"

class pao :public chess
{

	/*
		任意移动，走直线
	*/
public:


public:
	pao(bool player, int x, int y);//初始化与che相同
	~pao() {}
public:

	virtual bool move(int i, int j)
	{
		if (x == i)
		{
			if (y != j) return true;
		}
		else if (y == j)
		{
			if (x != i) return true;
		}
		return false;
	}

};

pao::pao(bool player, int x, int y)
{

	this->player = player;
	this->x = x;
	this->y = y;
	this->alive = true;

}
