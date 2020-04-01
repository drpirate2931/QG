#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

#include <iostream>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
	struct LNode* pre;
} LNode;

class LinkedList
{
public:
	LinkedList();								//构造函数，创建头结点（用于存放结点数
	void InsertAtTail(ElemType _data);			//在链表头部插入一个结点
	void InsertAtHead(ElemType _data);			//在链表尾部插入一个结点
	void DeleteNode(int deletePosition);		//用户指定位置删除结点
	void PrintList();							//打印链表

private:
	LNode* head;
};

#endif

