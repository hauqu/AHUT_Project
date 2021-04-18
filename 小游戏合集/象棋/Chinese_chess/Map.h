#pragma once
#include"jiang.h"
#include"shi.h"
#include"ma.h"
#include"che.h"
#include"bing.h"
#include"pao.h"
#include"xiang.h"

using std::vector;

class Map
{

public:
	
public:
	Map();
	~Map();
public:
	vector<chess*>cs;
	vector<string>csName;
public:
	int findChess(int i, int j);
	bool moveChess(int x1, int y1, int x2, int y2);
private:

};

Map::Map()
{
	
	cs.resize(32, nullptr);//32个棋子

	cs[(int)CHESS::b_jiang] = new jiang(1);
	cs[(int)CHESS::r_jiang] = new jiang(0);

	cs[(int)CHESS::b_shi1] = new shi(1, 3, 0);
	cs[(int)CHESS::b_shi2] = new shi(1, 5, 0);
	cs[(int)CHESS::r_shi1] = new shi(0, 3, 9);
	cs[(int)CHESS::r_shi2] = new shi(0, 5, 9);

	cs[(int)CHESS::b_xiang1] = new xiang(1, 2, 0);
	cs[(int)CHESS::b_xiang2] = new xiang(1, 6, 0);
	cs[(int)CHESS::r_xiang1] = new xiang(0, 2, 9);
	cs[(int)CHESS::r_xiang2] = new xiang(0, 6, 9);

	cs[(int)CHESS::b_ma1] = new ma(1, 1, 0);
	cs[(int)CHESS::b_ma2] = new ma(1, 7, 0);
	cs[(int)CHESS::r_ma1] = new ma(0, 1, 9);
	cs[(int)CHESS::r_ma2] = new ma(0, 7, 9);

	cs[(int)CHESS::b_che1] = new che(1, 0, 0);
	cs[(int)CHESS::b_che2] = new che(1, 8, 0);
	cs[(int)CHESS::r_che1] = new che(0, 0, 9);
	cs[(int)CHESS::r_che2] = new che(0, 8, 9);

	cs[(int)CHESS::b_pao1] = new pao(1, 1, 2);
	cs[(int)CHESS::b_pao2] = new pao(1, 7, 2);
	cs[(int)CHESS::r_pao1] = new pao(0, 1, 7);
	cs[(int)CHESS::r_pao2] = new pao(0, 7, 7);

	cs[(int)CHESS::b_bing1] = new bing(1, 0, 3);
	cs[(int)CHESS::b_bing2] = new bing(1, 2, 3);
	cs[(int)CHESS::b_bing3] = new bing(1, 4, 3);
	cs[(int)CHESS::b_bing4] = new bing(1, 6, 3);
	cs[(int)CHESS::b_bing5] = new bing(1, 8, 3);

	cs[(int)CHESS::r_bing1] = new bing(0, 0, 6);
	cs[(int)CHESS::r_bing2] = new bing(0, 2, 6);
	cs[(int)CHESS::r_bing3] = new bing(0, 4, 6);
	cs[(int)CHESS::r_bing4] = new bing(0, 6, 6);
	cs[(int)CHESS::r_bing5] = new bing(0, 8, 6);
	csName =
	{
		"jiang","=shi=","xiang","-ma*","&che&","|pao/",
				"=shi=","xiang","-ma*","&che&","|pao/",
				"|bin#","|bin#","|bin#","|bin#","|bin#",
		"shuai","=shi=","xiang","-ma*","&che&","|pao/",
				"=shi=","xiang","-ma*","&che&","|pao/",
				"|zu-|","|zu-|","|zu-|","|zu-|","|zu-|"
	};
	
}

Map::~Map()
{
	
}
inline int Map::findChess(int x, int y)
{
	for (int i = 0; i < 32; i++)
	{
		if(cs[i]!=nullptr)
		{
			if (cs[i]->x==x&&cs[i]->y==y)
			{
				return  i;
			}
		}
	}
	return -1;
}

inline bool Map::moveChess(int x1, int y1, int x2, int y2)
{

	int c1 = findChess(x1, y1);
	int c2 = findChess(x2, y2);
	bool m =cs[c1]->move(x2,y2);
	if (m == false) return false;//移动方式非法
	
	if (c1!=-1)
	{
		CHESS cc = (CHESS)c1;
		switch (cc)
		{
		case CHESS::b_jiang:
			break;
		case CHESS::b_shi1:
			break;
		case CHESS::b_xiang1:
			break;
		case CHESS::b_ma1:
			break;
		case CHESS::b_che1:
			//路程中间不能有 阻挡
			if(x1==x2)
			{
				bool cm = true;
				for (int i = x1+1; i <x2 ; i++)
				{
					 if(findChess(i, y1)!=-1)
					 {
						 cm = false;
					 }
				}
				if (cm==false)
				{
					return false;
				}
			}else if(y1 ==y2)
			{

			}
			break;
		case CHESS::b_pao1:
			break;
		case CHESS::b_shi2:
			break;
		case CHESS::b_xiang2:
			break;
		case CHESS::b_ma2:
			break;
		case CHESS::b_che2:
			break;
		case CHESS::b_pao2:
			break;
		case CHESS::b_bing1:
			break;
		case CHESS::b_bing2:
			break;
		case CHESS::b_bing3:
			break;
		case CHESS::b_bing4:
			break;
		case CHESS::b_bing5:
			break;
		case CHESS::r_jiang:
			break;
		case CHESS::r_shi1:
			break;
		case CHESS::r_xiang1:
			break;
		case CHESS::r_ma1:
			break;
		case CHESS::r_che1:
			break;
		case CHESS::r_pao1:
			break;
		case CHESS::r_shi2:
			break;
		case CHESS::r_xiang2:
			break;
		case CHESS::r_ma2:
			break;
		case CHESS::r_che2:
			break;
		case CHESS::r_pao2:
			break;
		case CHESS::r_bing1:
			break;
		case CHESS::r_bing2:
			break;
		case CHESS::r_bing3:
			break;
		case CHESS::r_bing4:
			break;
		case CHESS::r_bing5:
			break;
		default:
			break;
		}
	}else 
	{
		return false;
	}
	return false;
}
