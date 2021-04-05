/*
测试单链表的功能
*/

#include"singleList.h"
#include<iostream>
using namespace std;
int a[10] ={1,2,3,4,5,6,7,8,9,10};
int main(int argc,char **argv)
{
    singleList test = singleList(a,10);
    test.Print();
    for (int i = 0; i < 10; i++)
    {
        test.push_back(i);    
    }
    test.Print();
    for (int i = 0; i < 10; i++)
    {
        test.pop_back();    
    }
    test.Print();
    cout<<"测试完毕"<<endl;
    return 0;
}