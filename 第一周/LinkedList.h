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
    LinkedList();                           //���캯��������ͷ��㣨ͷ������ڴ������ڵ���Ŀ
    void InsertAtTail(ElemType _data);      //�������β������һ�����
    void DestroyList();                     //������������ͷ���
    void DeleteNode(int deletePosition);    //���û�ָ����λ��ɾ��һ�����
    void SearchList(ElemType value);        //�����û������ֵ���ҽ���λ��
    void ReverseList();                     //��ת����
    bool IsLoopList();                      //�ж������Ƿ�ɻ�
    void ReverseEvenList();                 //������ĳɶԷ�ת �磺1->2->3->4 ��ת�� 2->1->4->3
    void FindMidNode();                     //�ҵ�������м��㣨�����ż���Ļ����ǿ������һλ
    void PrintList();                       //��ӡ����

private:
    LNode* head;
};

#endif
