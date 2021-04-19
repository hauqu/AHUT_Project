#pragma once
/*
用来与玩家进行连接，只有处于连接中的玩家可以加入房间并开始游戏

*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS //头文件升级原因导致原有函数报错，加上这句忽略报错
#include <stdio.h>
#include <winsock2.h>//windows 下的socket2.2
#include<iostream>
#include<string>
#pragma comment(lib,"ws2_32.lib")  //使用socket必须加载库
using namespace std;
class Server 
{
public:
	Server();
	int startServer();//服务器开启连接允许

public:
	~Server();
protected:
	WORD sockVersion;
	WSADATA wsaData;
	SOCKET slisten;
};
inline Server::Server()
{
	//初始化WSA  
	//启动一个2.2网络协议
	sockVersion = MAKEWORD(2, 2);
	
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		printf("Version error !");
	}
	slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//使用TCP 进行通信
	if (slisten == INVALID_SOCKET)
	{
		printf("socket error !");
		
	}
	//绑定IP和端口  
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(12345);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("bind error !");
	}
	//开始监听  
	if (listen(slisten, SOMAXCONN))//SOMAXCONN 队列等待处理最大连接个数
	{
		printf("listen error !");
		
	}
}
inline Server::~Server()
{

}
int Server::startServer()
{
	
}