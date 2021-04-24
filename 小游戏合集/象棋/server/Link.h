#pragma once
/*

不负责收发数据，只负责提供数据存储和设置标志位

*/
#include<string>
#include <winsock2.h>//windows 下的socket2.2
#pragma comment(lib,"ws2_32.lib")  //使用socket必须加载库
using namespace std;
class Link
{
public:
	string r;//接受的数据
	string s;//发送的数据
	SOCKET sClient;
	string name;
	char revData[255];
	const char* sendData;
	void sendS(string s)
	{
		this->s = s;
		ableS = true;
	}
	void recvR()
	{
		this->r = "";
		ableR = true;
	}
public:
	Link(SOCKET& c, string l_name);


	bool ableR;
	bool ableS;
};
Link::Link(SOCKET& c, string l_name)
{
	sClient = c;
	ableR = false;
	ableS = false;
	name = l_name;

}