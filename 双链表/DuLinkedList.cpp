#include "DuLinkedList.h"

LinkedList::LinkedList()
{
	head = new LNode;
	head->data = 0;
	head->next = head->pre = head;
}

void LinkedList::InsertAtTail(ElemType _data)
{
	LNode* temp = head;
	LNode* newN = new LNode;
	newN->data = _data;

	newN->next = head;
	newN->pre = head->pre;
	head->pre->next = newN;
	head->pre = newN;
	head->data += 1;

}

void LinkedList::InsertAtHead(ElemType _data)
{
	LNode* temp = head;
	LNode* newN = new LNode;
	newN->data = _data;

	newN->next = head->next;
	newN->pre = head;
	head->next = newN;
	newN->next->pre = newN;
	head->data += 1;
}

void LinkedList::DeleteNode(int deletePosition)
{
	LNode* temp = head;
	if (deletePosition == 0)
	{
		head = head->next;
		head->pre = temp->pre;
		temp->pre->next = head;
		head->data -= 1;
		delete temp;
	}
	else
	{
		for (int i = 0; i < deletePosition - 1; i++)
		{
			temp = temp->next;
		}
		LNode* p = temp->next;
		temp->next = temp->next->next;
		temp->next->next->pre = temp;
		head->data -= 1;
		delete p;
	}
}

void LinkedList::PrintList()
{
	if (head->data == 0)
	{
		std::cout << "The list has no node" << std::endl;
		puts("\n");
		return;
	}
	LNode* temp = head->next;
	std::cout << "The list has " << head->data << " nodes" << std::endl;
	while (temp != head)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	puts("\n");
}
