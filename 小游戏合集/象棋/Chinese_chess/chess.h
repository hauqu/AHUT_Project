#pragma once
/*
	��������ϵ
	���Ͻ�Ϊ 00�����½�Ϊwh

	ֻ��Ҫ��������������������Ĺ�ϵ
	���仯���ݸ������������ܵó���ȷ�ĸı䡣
	�������а�����������Ϣ���ͻ��˻�ȡ�������ڻ���


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
//0 �� 1 �ڣ���ɫ���� ����ɫ����

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
	//���ݵ�����Ϊ���ָ��������λ�ã������߽紦��
	//ֻ���Ƿ�����ƶ�����δ����ڴ����ְ����
	//Ӧ�ý���map����
	virtual ~chess(){}
public:
	static  int MapRow ;
	static  int MapCol ;
	static  int chessR;//���Ӱ뾶
	static  int RedHomeRow;//�췽��������
	static  int RedHomeCol;//�췽��������
	static  int BlackHomeRow;//�ڷ���������
	static  int BlackHomeCol;//�ڷ���������
	static  int BlackRiverCol;//���
	static  int RedRiverCol;//���
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