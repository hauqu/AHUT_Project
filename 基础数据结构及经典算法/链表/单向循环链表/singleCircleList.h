/*
    链表的结点
*/
#pragma once
#include<iostream>

class node_singleCircleList
{

public:
    int date;
    node_singleCircleList* next;
public:
    node_singleCircleList(int d):
        date(d),next(nullptr)
        {

        }
    node_singleCircleList(int d,node_singleCircleList*n):
        date(d),next(n)
        {

        }
    node_singleCircleList():
        date(0),next(nullptr)
        {

        }
public:
    ~node_singleCircleList(){}
};

/*
    一个最简单的单向循环链表
    包含一个后继指针和一个整数数据域
    带一个根节点，内容为节点内容
    不允许完全为空，至少保留根节点
    
*/
class singleCircleList
{

public:
    node_singleCircleList *root;//根节点,存放长度

public:
    singleCircleList()
        {
            root =new node_singleCircleList(0);
            root->next = root;
        }
    singleCircleList(int l)//长度为l ，默认值0
        {
            root =new node_singleCircleList(0);
            node_singleCircleList* start=root;
           
            for (int i = 1; i < l; i++)
            {
                node_singleCircleList* temp =new node_singleCircleList;
                start->next = temp;
                start =start->next;
            }
            start->next =root;
        }
    singleCircleList(int *arr,int l)//将数组转换为链表
        {
            root = new node_singleCircleList(arr[0]);
            node_singleCircleList* start=root;
           
            for (int i = 1; i < l; i++)
            {
                node_singleCircleList* temp =new node_singleCircleList(arr[i]);
                start->next = temp;
                start =start->next;
            }
            start->next =root;
        }
public:
    void Print(void)//打印链表
    {
        if(root==nullptr) 
        {
            std::cout<<"链表是空的"<<std::endl;
            return ;
        }
        std::cout<<root->date<<" ";
        node_singleCircleList*temp = root->next;
        while (temp!=root)
        {
            std::cout<<temp->date<<" ";
            temp =temp->next;
        }
        std::cout<<std::endl;
        
    }
public:
    void push(int d)//在根节点后面插入一个元素
    {
        node_singleCircleList* temp = new node_singleCircleList(d,root->next);
        root->next =temp;
    }
public:

    ~singleCircleList()
    {
        node_singleCircleList*start =root->next;
        while (start!=root)
        {
            node_singleCircleList* temp =start;
            start =start->next;
            delete temp;
        }
        delete root;

    }

};