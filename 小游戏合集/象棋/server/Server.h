#pragma once
/*
��������ҽ������ӣ�ֻ�д��������е���ҿ��Լ��뷿�䲢��ʼ��Ϸ

*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS //ͷ�ļ�����ԭ����ԭ�к����������������Ա���
#include <stdio.h>
#include <winsock2.h>//windows �µ�socket2.2
#include<iostream>
#include<string>
#pragma comment(lib,"ws2_32.lib")  //ʹ��socket������ؿ�
using namespace std;
class Server 
{
public:
	Server();
	int startServer();//������������������

public:
	~Server();
protected:
	WORD sockVersion;
	WSADATA wsaData;
	SOCKET slisten;
};
inline Server::Server()
{
	//��ʼ��WSA  
	//����һ��2.2����Э��
	sockVersion = MAKEWORD(2, 2);
	
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		printf("Version error !");
	}
	slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//ʹ��TCP ����ͨ��
	if (slisten == INVALID_SOCKET)
	{
		printf("socket error !");
		
	}
	//��IP�Ͷ˿�  
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(12345);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("bind error !");
	}
	//��ʼ����  
	if (listen(slisten, SOMAXCONN))//SOMAXCONN ���еȴ�����������Ӹ���
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