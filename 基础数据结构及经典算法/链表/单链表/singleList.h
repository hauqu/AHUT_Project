/*
    链表的结点
*/
#pragma once
#include<iostream>

class node_singleList
{

public:
    int date;
    node_singleList* next;
public:
    node_singleList(int d):
        date(d),next(nullptr)
        {

        }
    node_singleList(int d,node_singleList*n):
        date(d),next(n)
        {

        }
    node_singleList():
        date(0),next(nullptr)
        {

        }
public:
    ~node_singleList(){}
};

/*
    一个最简单的单链表
    包含一个后继指针和一个整数数据域
    带一个头节点，内容为链表的长度
    方便静态查询
*/
class singleList
{

public:
    node_singleList *head;//头节点,存放长度

public:
    singleList()
        {
            head =new node_singleList(0);
        }
    singleList(int l)//长度为l ，默认值0
        {
            head =new node_singleList(l);
            node_singleList* start=head;
           
            for (int i = 0; i < l; i++)
            {
                node_singleList* temp =new node_singleList;
                start->next = temp;
                start =start->next;
            }
            start->next =nullptr;
        }
    singleList(int *arr,int l)//将数组转换为链表
        {
            head =new node_singleList(l);
            node_singleList* start=head;
           
            for (int i = 0; i < l; i++)
            {
                node_singleList* temp =new node_singleList(arr[i]);
                start->next = temp;
                start =start->next;
            }
            start->next =nullptr;
        }
public:
    void Print(void)//打印链表
    {
        if(head->next ==nullptr) std::cout<<"链表是空的"<<std::endl;
        node_singleList*temp = head->next;
        while (temp)
        {
            std::cout<<temp->date<<" ";
            temp =temp->next;
        }
        std::cout<<std::endl;
        
    }
public:
    node_singleList* back()
    {
        node_singleList *temp =head->next;
        while (temp->next)
        {
            temp =temp->next;
        }
        return temp;
    }
    void push_back(int d)//在末尾添加一个元素
    {
        node_singleList *t =back();
        t->next =new node_singleList(d);
        head->date++;
    }
    int pop_back()//删除末尾的一个元素
    {
        if(head->next ==nullptr)
        {
            return 0;//空链表
        }else
        {
            node_singleList* temp =head;
            while (temp->next->next)
            {
                temp =temp->next;
            }
            int date =temp->next->date;//读值
            delete  temp->next;//释放内存
            
            temp->next =nullptr;//指空
            head->date--;//修改长度
           //std::cout<<date<<std::endl;
            return date;
        }
    }
public:
    ~singleList()
    {
      node_singleList* start=head;
      int l =head->date;  
      while (start)
      {
          node_singleList*temp =start;
          start =start->next;
          delete temp;
      }
      delete head;
    }
};