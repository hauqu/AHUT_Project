#pragma once

#include"chess.h"


class jiang :public chess
{
/*
	在大本营移动，一次一格

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

		//一次一格，必须在固定区域
		if (i > homeRow + 1 || i < homeRow - 1)
			return false;
		if (j > homeCol + 1 || j < homeCol - 1)
			return false;
		if (i == x && j == y) return false;//需要告知自己能不能踩到自己
		//区域限定

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
		//一次一格
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