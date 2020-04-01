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
	LinkedList();								//���캯��������ͷ��㣨���ڴ�Ž����
	void InsertAtTail(ElemType _data);			//������ͷ������һ�����
	void InsertAtHead(ElemType _data);			//������β������һ�����
	void DeleteNode(int deletePosition);		//�û�ָ��λ��ɾ�����
	void PrintList();							//��ӡ����

private:
	LNode* head;
};

#endif

