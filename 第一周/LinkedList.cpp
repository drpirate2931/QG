#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = new LNode;
    head->data = 0;
    head->next = NULL;
}
void LinkedList::InsertAtTail(ElemType _data)
{
    LNode* temp = head;
    LNode* newN = new LNode;
    newN->data = _data;
    newN->next = NULL;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newN;
    head->data += 1;
}

void LinkedList::DestroyList()
{
    if (head->data == 0)
    {
        std::cout << "The list has no node" << std::endl;
        puts("\n");
        return;
    }
    LNode* temp;
    if (head->next == NULL) return;

    while (head->next)
    {
        temp = head->next->next;
        delete head->next;
        head->next = temp;
    }
    head->data = 0;
}

void LinkedList::DeleteNode(int deletePosition)
{
    LNode* temp = head->next;
    if (deletePosition == 1)
    {
        head->next = temp->next;
        delete temp;
        head->data -= 1;
    }
    else if (deletePosition == head->data)
    {
        for (int i = 0; i < deletePosition - 2; i++)
        {
            temp = temp->next;
        }
        LNode* p = temp->next;
        temp->next = NULL;
        delete p;
        head->data -= 1;
    }
    else
    {
        for (int i = 0; i < deletePosition - 2; i++)
        {
            temp = temp->next;
        }
        LNode* q = temp->next;
        temp->next = temp->next->next;
        delete q;
        head->data -= 1;
    }
}
void LinkedList::SearchList(ElemType value)
{
    if (head->data == 0)
    {
        std::cout << "The list has no node" << std::endl;
        puts("\n");
        return;
    }
    int i = 0;
    LNode* temp = head->next;
    while (temp)
    {
        i++;
        if (temp->data == value)
        {
            std::cout << "the value you've searched for is at position " << i << std::endl;
            puts("\n");
            return;
        }
        
        temp = temp->next;
    }
    std::cout << "the value you've searched for doesn't exit" << std::endl;
    puts("\n");
}

void LinkedList::ReverseList()
{
    if (head->data == 0)
    {
        std::cout << "The list has no node" << std::endl;
        puts("\n");
        return;
    }
    LNode* temp1 = head->next;
    LNode* temp;
    LNode* tail;
    tail = NULL;
    while (temp1 != NULL)
    {
        temp = temp1->next;
        temp1->next = tail;
        tail = temp1;
        temp1 = temp;
    }
    head->next = tail;
}

bool LinkedList::IsLoopList()
{
    if (head->data == 0)
    {
        std::cout << "The list has no node" << std::endl;
        puts("\n");
        return false;
    }

    LNode* l1 = head, * l2 = head->next;
    while (l1 != NULL && l2 != NULL && l2->next != NULL)
    {
        if (l1 == l2) return true;
        l1 = l1->next;
        l2 = l2->next->next;
    }

    return false;
}
void LinkedList::ReverseEvenList()
{
    if (head->data == 0)
    {
        std::cout << "The list has no node" << std::endl;
        return;
    }
    LNode* current = head;
    
    
    while (current->next != NULL && current->next->next != NULL)
    {
        LNode* first = current->next;
        LNode* second = current->next->next;

        first->next = second->next;
        second->next = first;
        current->next = second;
        current = current->next->next;
    }
}
void LinkedList::FindMidNode()
{
    if (head->data == 0)
    {
        std::cout << "The list has no node" << std::endl;
        return;
    }
    LNode* l1 = head->next, * l2 = head->next;
    if (head->next == NULL) return;
    while (l2 != NULL)
    {
        l1 = l1->next;
        l2 = l2->next->next;
    }
    std::cout << "the data of the middle position of the list is : " << l1->data << std::endl;
    puts("\n");
}

void LinkedList::PrintList()
{
    if (head->next == NULL)
    {
        std::cout << "the list has no node" << std::endl;
        puts("\n");
        return;
    }
    LNode* temp = head->next;
    std::cout << "The List has " << head->data << " nodes" << std::endl;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    puts("\n");
}