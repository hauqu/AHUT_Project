#pragma once
/*
	绝对坐标系
	左上角为 00，右下角为wh

	只需要建立玩家坐标与绝对坐标的关系
	将变化传递给服务器，就能得出正确的改变。
	服务器中包含了所有信息，客户端获取部分用于绘制


*/


//0 红 1 黑，黑色在上 ，红色在下
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