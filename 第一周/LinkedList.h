#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode;

class LinkedList
{
public:
    LinkedList();                           //构造函数，创建头结点（头结点用于存放链表节点数目
    void InsertAtTail(ElemType _data);      //在链表的尾部插入一个结点
    void DestroyList();                     //销毁链表，保留头结点
    void DeleteNode(int deletePosition);    //在用户指定的位置删除一个结点
    void SearchList(ElemType value);        //根据用户输入的值查找结点的位置
    void ReverseList();                     //反转链表
    bool IsLoopList();                      //判断链表是否成环
    void ReverseEvenList();                 //链表结点的成对反转 如：1->2->3->4 反转后 2->1->4->3
    void FindMidNode();                     //找到链表的中间结点（如果是偶数的话就是靠后的那一位
    void PrintList();                       //打印链表

private:
    LNode* head;
};

#endif
