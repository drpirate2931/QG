#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template<typename T>
struct node
{
	T data;
	node<T>* next;

	node() :next(nullptr) {};
	node(T t) :data(t), next(nullptr) {};
};

template<typename T>
class LinkStack
{
private:
	int count;
	node<T>* head;

public:
	LinkStack();
	~LinkStack();
	bool isEmptyStack();
	bool getTopLStack(T* e);
	bool pushLStack(T data);
	bool popLStack(T* e);
	bool LStackLength(T* length);
	bool clearLStack();
	void printLStack();
};

template<typename T>
LinkStack<T>::LinkStack()
{
	count = 0;
	head = new node<T>;
}

template<typename T>
LinkStack<T>::~LinkStack()
{
	if (head->next != nullptr)
	{
		node<T>* temp = head->next;
		while (temp != nullptr)
		{
			node<T>* p = temp;
			temp = temp->next;
			delete p;
		}
		head->next = nullptr;
		delete head;
		count = 0;
	}
}

template<typename T>
bool LinkStack<T>::isEmptyStack()
{
	if (count)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<typename T>
bool LinkStack<T>::getTopLStack(T* e)
{
	if (head->next != nullptr)
	{
		*e = head->next->data;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool LinkStack<T>::pushLStack(T data)
{
	node<T>* nNode = new node<T>(data);
	nNode->next = head->next;
	head->next = nNode;
	count++;
	return true;
}

template<typename T>
bool LinkStack<T>::popLStack(T* e)
{
	if (head->next != nullptr)
	{
		node<T>* temp = head->next;
		head->next = head->next->next;
		T popData = temp->data;
		delete temp;
		*e = popData;
		count--;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool LinkStack<T>::LStackLength(T* length)
{
	if (count)
	{
		*length = count;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool LinkStack<T>::clearLStack()
{
	if (head->next != nullptr)
	{
		node<T>* temp = head->next;
		while (temp != nullptr)
		{
			node<T>* p = temp;
			temp = temp->next;
			delete p;
		}
		head->next = nullptr;
		count = 0;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void LinkStack<T>::printLStack()
{
	if (head->next != nullptr)
	{
		node<T>* temp = head->next;
		while (temp != nullptr)
		{
			cout << temp->data << ' ';
			temp = temp->next;
		}
	}
	else
	{
		cout << "The stack has no value" << endl;
	}
}

#endif
