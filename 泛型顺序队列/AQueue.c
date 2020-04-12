#include "AQueue.h"

void InitAQueue(AQueue* Q)
{
	Q->length = MAXQUEUE;
	for (int i = 0; i < MAXQUEUE; i++)
	{
		Q->data[i] = (void*)malloc(21);
	}
	Q->front = Q->rear = 0;
}

void DestoryAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf("The queue is not initialized!\n");
		return;
	}
	for (int i = 0; i < MAXQUEUE; i++)
	{
		free(Q->data[i]);
	}
	Q->data[0] = NULL;
}

Status IsFullAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf("The queue is not initialized!\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		return FALSE;
	}
	if (LengthAQueue(Q) == MAXQUEUE - 1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status IsEmptyAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf("The queue is not initialized!\n");
		return FALSE;
	}
	return (LengthAQueue(Q) == 0 ? TRUE : FALSE);
}

Status GetHeadAQueue(AQueue* Q, void* e)
{
	if (IsEmptyAQueue(Q))
	{
		printf("The queue is empty!\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front], 20);
	return TRUE;
}

int LengthAQueue(AQueue* Q)
{
	return (Q->rear - Q->front + Q->length) % Q->length;
}

Status EnAQueue(AQueue* Q, void* data)
{
	if (Q->data[0] == NULL)
	{
		printf("The queue is not initialized!\n");
		return FALSE;
	}
	if (IsFullAQueue(Q))
	{
		printf("The queue is full!\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		memcpy(Q->data[Q->front], data, 20);
		Q->rear = (Q->rear + 1) % Q->length;
		return TRUE;
	}
	memcpy(Q->data[Q->rear], data, 20);
	Q->rear = (Q->rear + 1) % Q->length;
	return TRUE;
}

Status DeAQueue(AQueue* Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("The queue is empty!\n");
		return FALSE;
	}
	Q->front = (Q->front + 1) % Q->length;
	return TRUE;
}

void ClearAQueue(AQueue* Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("The queue is empty!\n");
		return;
	}
	Q->front = Q->rear = 0;
}

Status TraverseAQueue(AQueue* Q, void (*foo)(void* q, int typeData))
{
	if (Q->data[0] == NULL)
	{
		printf("The queue is not initialized!\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		printf("The queue is empty!\n");
		return FALSE;
	}
	int i = 0;
	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE)
	{
		foo(Q->data[Q->front + i], type[Q->front + i]);
		i = (i + 1) % MAXQUEUE;
	}
	return TRUE;
}

void APrint(void* q, int typeData)
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

