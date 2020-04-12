#include "LQueue.h"

void InputData();
void Menu();

int main(void)
{
	system("color F0");
	e = malloc(21);
	Q = (LQueue*)malloc(sizeof(LQueue));
	Menu();

	return 0;
}

void Menu()
{
	while (1)
	{
		printf("Which function you want to choose:\n");
		printf("1.Init queue\n");
		printf("2.Destroy queue\n");
		printf("3.judge if the queue is empty\n");
		printf("4.get the head data of the queue\n");
		printf("5.get the length of the queue\n");
		printf("6.push a data into the queue\n");
		printf("7.pop a data out of the queue\n");
		printf("8.clear the queue\n");
		printf("9.traverse the queue\n");
		printf("0.quit\n");

		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			InitLQueue(Q);
			continue;
		case 2:
			DestoryLQueue(Q);
			continue;
		case 3:
			if (IsEmptyLQueue(Q))
			{
				printf("the queue is empty\n");
				continue;
			}
			else
			{
				printf("the queue is not empty\n");
				continue;
			}
		case 4:
			if (GetHeadLQueue(Q, e))
			{
				printf("succeeded!\n");
				continue;
			}
			else
			{
				printf("failed!\n");
				continue;
			}
		case 5:
			printf("the length is %d\n", LengthLQueue(Q));
			continue;
		case 6:
			InputData();
			continue;
		case 7:
			if (DeLQueue(Q))
			{
				printf("succeeded!\n");
				continue;
			}
			else
			{
				printf("failed!\n");
				continue;
			}
		case 8:
			ClearLQueue(Q);
			continue;
		case 9:
			if (TraverseLQueue(Q, LPrint))
			{
				printf("succeeded!\n");
				continue;
			}
			else
			{
				printf("failed!\n");
				continue;
			}
		case 0:
			return;
		}
	}
}

void InputData()
{
	printf("Which element type you want to pop into the queue ? :\n");
	printf("1. int 2. char 3. double 4. string\n");
	scanf("%d", &t);
	while (t < 1 || t > 4)
	{
		printf("You should input a number between 1 and 4\nPlease re-input : ");
		scanf("%d", &t);
	}
	printf("The data u want to input is: ");
	switch (t)
	{
	case INT:;
		int a;
		scanf("%d", &a);
		EnLQueue(Q, &a);
		Q->rear->type = t;
		
		break;
	case CHAR:;
		char b;
		getchar();
		scanf("%c", &b);
		EnLQueue(Q, &b);
		Q->rear->type = t;

		break;
	case DOUBLE:;
		double c;
		scanf("%lf", &c);
		EnLQueue(Q, &c);
		Q->rear->type = t;

		break;
	case STRING:;
		char d[20];
		printf("The max length is 20\n");
		scanf("%s", &d);
		EnLQueue(Q, &d);
		Q->rear->type = t;

		break;
	}
}