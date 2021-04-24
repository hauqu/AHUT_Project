#pragma once
#include<iostream>
using std::string;

class DataStruct
{
public:
	int x1, y1;
	int x2, y2;
public:
	DataStruct(string data);
};
DataStruct::DataStruct(string data)
{
	x1 = data[0] - '0';
	x2 = data[1] - '0';
	y1 = data[2] - '0';
	y2 = data[3] - '0';
}