#pragma once
/*
	绝对坐标系
	左上角为 00，右下角为wh

	只需要建立玩家坐标与绝对坐标的关系
	将变化传递给服务器，就能得出正确的改变。
	服务器中包含了所有信息，客户端获取部分用于绘制


*/
#include<vector>
class point2
{
public:
	int x;
	int y;
	point2(int a,int b)
	{
		x = a; y = b;
	}

};
//0 红 1 黑，黑色在上 ，红色在下

enum class CHESS
{
	b_jiang=0,
	b_shi1,b_xiang1,b_ma1,b_che1,b_pao1,
	b_shi2, b_xiang2, b_ma2, b_che2, b_pao2,
	b_bing1, b_bing2, b_bing3, b_bing4, b_bing5,
	r_jiang,
	r_shi1, r_xiang1, r_ma1, r_che1, r_pao1,
	r_shi2, r_xiang2, r_ma2, r_che2, r_pao2,
	r_bing1, r_bing2, r_bing3, r_bing4, r_bing5,
};
class chess
{
public:
	int x; int y;
	bool alive;
	bool player;

public:
	virtual bool move(int i,int j)= 0;
	//传递的内容为玩家指定的任意位置，不做边界处理
	//只做是否可以移动，如何处理不在此类的职责内
	//应该交给map处理
	virtual ~chess(){}
public:
	static  int MapRow ;
	static  int MapCol ;
	static  int chessR;//棋子半径
	static  int RedHomeRow;//红方主场中心
	static  int RedHomeCol;//红方主场中心
	static  int BlackHomeRow;//黑方主场中心
	static  int BlackHomeCol;//黑方主场中心
	static  int BlackRiverCol;//界河
	static  int RedRiverCol;//界河
};

int  chess::MapRow = 9;
int  chess::MapCol = 10;

int chess::chessR = 1;

int chess::BlackHomeRow = 4;
int chess::BlackHomeCol = 1;

int chess::RedHomeRow = 4;
int chess::RedHomeCol = 8;

int chess::RedRiverCol = 5;
int chess::BlackRiverCol = 4;