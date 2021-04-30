#pragma once
/*
	通过 Link 通信，由线程client 启动 communicate 将数据存储到 Link 对象中
*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS //头文件升级原因导致原有函数报错，加上这句忽略报错
#include <stdio.h>
#include"Link.h"
#include<iostream>
#include<thread>

using namespace std;


void communicate(Link& l);

class Client
{
public:
	WORD sockVersion;
	WSADATA wsaData;
	SOCKET sclient;
	string ServerIp;
	Link  *player;
	thread client;
public:
	Client(string ip);
	~Client();

};





Client::Client(string ip)
{

	//初始化WSA  
	//启动一个2.2网络协议
	ServerIp = ip;
	sockVersion = MAKEWORD(2, 2);

	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		printf("Version error !");
	}else
	{
		cout << "客户端协议2.2启动成功" << endl;
	}
	sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sclient == INVALID_SOCKET)
	{
		printf("invalid socket!");
	}
	else
	{
		cout << "Socket创建成功" << endl;
	}
	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(12345);
	const char* sip = ServerIp.c_str();
	serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	//127.0.0.1 本地回环地址

	bool falg =true;
	while (falg)
	{
		if (connect(sclient, (sockaddr*)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
		{
			cout << "客户端连接失败" << endl;
			this_thread::sleep_for(1s);
		}
		else
		{
			falg = false;
			cout << "客户端连接成功" << endl;
			//send(sclient, "这里客户端\n", 14, 0);
		}
	}
	
	player = new Link(sclient,"客户端连接");
	client = thread(communicate, std::ref(*player));
	
}

inline Client::~Client()
{
	closesocket(sclient);
	WSACleanup();
	
}
void communicate(Link& l)
{
	
	while (true)
	{
		if (!l.ableR && !l.ableS)
		{
			this_thread::sleep_for(0.5s);
		}
		if (l.ableS)
		{
			l.sendData = l.s.c_str();
			send(l.sClient, l.sendData, strlen(l.sendData), 0);
			l.ableS = false;
		}
		if (l.ableR)
		{
			int rec = 0;
			rec = recv(l.sClient, l.revData, 255, 0);
			if (rec > 0)//接收到数据
			{
				l.revData[rec] = '\0';
				l.r = l.revData;
				rec = 0;
			}
			l.ableR = false;
		}
		

	}
}