#pragma once
/*
	��������ϵ
	���Ͻ�Ϊ 00�����½�Ϊwh

	ֻ��Ҫ��������������������Ĺ�ϵ
	���仯���ݸ������������ܵó���ȷ�ĸı䡣
	�������а�����������Ϣ���ͻ��˻�ȡ�������ڻ���


*/


//0 �� 1 �ڣ���ɫ���� ����ɫ����
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