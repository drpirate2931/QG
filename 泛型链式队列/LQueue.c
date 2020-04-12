#include "LQueue.h"

void InitLQueue(LQueue* Q)
{
	Q->front = Q->rear = NULL;
	Q->length = 0;
}

void DestoryLQueue(LQueue* Q)
{
	if (Q->length == 0)
	{
		printf("The queue is empty\n");
		return;
	}
	Node* temp;
	while (Q->front->next)
	{
		temp = Q->front->next;
		free(Q->front);
		Q->front = temp;
	}
	Q->front = Q->rear = NULL;
	Q->length = 0;
}

Status IsEmptyLQueue(LQueue* Q)
{
	if (Q->length == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status GetHeadLQueue(LQueue* Q, void* e)
{
	if (Q->length == 0)
	{
		printf("The queue is empty!\n");
		return FALSE;
	}
	e = Q->front->data;
	return TRUE;
}

int LengthLQueue(LQueue* Q)
{
	return Q->length;
}

Status EnLQueue(LQueue* Q, void* data)
{
	if (Q->length == 0)
	{
		Node* newN = (Node*)malloc(sizeof(Node));
		newN->data = (void*)malloc(21);
		memcpy(newN->data, data, 20);
		newN->next = NULL;

		Q->front = Q->rear = newN;
		Q->length++;

		return TRUE;
	}
	Node* newN1 = (Node*)malloc(sizeof(Node));
	newN1->data = (void*)malloc(21);
	memcpy(newN1->data, data, 20);
	newN1->next = NULL;

	Q->rear->next = newN1;
	Q->rear = newN1;
	Q->length++;

	return TRUE;
}

Status DeLQueue(LQueue* Q)
{
	if (Q->length == 0)
	{
		printf("The queue is empty!\n");
		return FALSE;
	}
	Node* temp = Q->front;
	Q->front = Q->front->next;
	free(temp);
	Q->length--;
	return TRUE;
}

void ClearLQueue(LQueue* Q)
{
	if (Q->length == 0)
	{
		printf("The queue is empty!\n");
		return;
	}
	Node* temp;
	while (Q->front->next)
	{
		temp = Q->front->next;
		free(Q->front);
		Q->front = temp;
	}
	Q->front = Q->rear = NULL;
	Q->length = 0;
}

Status TraverseLQueue(LQueue* Q, void (*foo)(void* q, int type))
{
	
	if (Q->length == 0)
	{
		printf("The queue is empty!\n");
		return FALSE;
	}
	Node* temp = Q->front;
	for (int i = 0; i < Q->length; i++)
	{
		foo(temp->data, temp->type);
		temp = temp->next;
	}
	return TRUE;
}

void LPrint(void* q, int typeData)
{
	if (typeData == DOUBLE)
		printf("--> %.2lf", *(double*)q);
	if (typeData == CHAR)
		printf("--> %c", *(char*)q);
	if (typeData == INT)
		printf("--> %d ", *(int*)q);
	if (typeData == STRING)
		printf("--> %s ", (char*)q);
}