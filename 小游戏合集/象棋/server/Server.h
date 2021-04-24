#pragma once
/*

thread listenServer 用于 循环监听建立连接
通过 Link 通信，由线程LinkServer 启动 communicate 将数据存储到 Link 对象中

*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS 
//头文件升级原因导致原有函数报错，加上这句忽略报错
#include <stdio.h>
#include<iostream>
#include<thread>
#include<vector>
#include<string>
#include"Link.h"
#pragma comment(lib,"ws2_32.lib")  //使用socket必须加载库


/*
using std::vector;
using std::cout;
using std::endl;
*/
using namespace std;

void communicate(Link& l);



class Server 
{
public:
	Server(u_short port);
	
	vector<Link*>players;//连接的玩家们
public:
	~Server();
public:
	static const int MAX_LINK=4;
public:
	WORD sockVersion;
	WSADATA wsaData;
	SOCKET slisten;
public:
	thread listenServer;
	thread linkServer[MAX_LINK];

};

void StartListen(Server& ser);
inline Server::Server(u_short port)
{
	//初始化WSA  
	//启动一个2.2网络协议
	sockVersion = MAKEWORD(2, 2);
	
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		cout << "服务端协议2.2启动失败" << endl;
	}
	else
	{
		cout << "服务端协议2.2启动成功" << endl;
	}
	slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//使用TCP 进行通信
	if (slisten == INVALID_SOCKET)
	{
		cout << "服务端套接字创建失败" << endl;
		
	}
	else
	{
		cout << "服务端套接字创建成功" << endl;
	}
	//绑定IP和端口  
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (::bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		cout << "服务端套接字绑定失败 " << endl;
	}
	else
	{
		cout << "服务端套接字绑定成功 "<< endl;
	}
	listenServer = thread(StartListen, std::ref(*this));
}
inline Server::~Server()
{
	closesocket(slisten);
	WSACleanup();
	
}
inline void StartListen(Server& ser)
{
	if (listen(ser.slisten, SOMAXCONN) == ser.MAX_LINK)//等待处理最大连接个数
	{
		cout << "无法继续监听" << endl;
	}
	else
	{
		cout << "成功打开监听" << endl;
	}
	
	while (ser.players.size()<ser.MAX_LINK)
	{
		SOCKET sClient;
		sockaddr_in remoteAddr;
		int nAddrlen = sizeof(remoteAddr);
		cout << "<正在监听>" << endl;
		cout << "现在有 " << ser.players.size() << " 个连接" << endl;
		sClient = accept(ser.slisten, (SOCKADDR*)&remoteAddr, &nAddrlen);
		
		cout << "开始连接" << endl;
		if (sClient == INVALID_SOCKET)
		{
			this_thread::sleep_for(100ms);
			cout << "连接失败" << endl;
			continue;//
		}
		else// 连接成功
		{
			int i = ser.players.size();
			printf("接受到一个连接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));
			cout << "连接成功" << endl;
			
			Link* temp = new Link(sClient, inet_ntoa(remoteAddr.sin_addr));
			ser.players.push_back(temp);
			ser.linkServer[i] = thread(communicate, std::ref(*ser.players[i]));
			
		}
		this_thread::sleep_for(100ms);
		
	}
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
		}

		

	}
}