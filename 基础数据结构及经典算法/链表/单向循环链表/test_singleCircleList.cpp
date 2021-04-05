/*
测试单链表的功能
*/

#include"singleCircleList.h"
#include<iostream>
using namespace std;
int a[10] ={1,2,3,4,5,6,7,8,9,10};
int main(int argc,char **argv)
{
    singleCircleList test = singleCircleList(a,10);
    test.Print();
    cout<<"测试完毕"<<endl;
    return 0;
}