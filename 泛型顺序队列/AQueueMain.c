#include "AQueue.h"

void InputData();
void Menu();


int main(void)
{
	system("color F0");
	e = malloc(21);
	Q = (AQueue*)malloc(sizeof(AQueue));
	Q->data[0] = NULL;
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
		printf("3.judge if the queue is full\n");
		printf("4.judge if the queue is empty\n");
		printf("5.get the head data of the queue\n");
		printf("6.get the length of the queue\n");
		printf("7.push a data into the queue\n");
		printf("8.pop a data out of the queue\n");
		printf("9.clear the queue\n");
		printf("10.traverse the queue\n");
		printf("0.quit\n");

		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			InitAQueue(Q);
			continue;
		case 2:
			DestoryAQueue(Q);
			continue;
		case 3:
			if (IsFullAQueue(Q))
			{
				printf("the queue is full\n");
				continue;
			}
			else
			{
				printf("the queue is not full\n");
				continue;
			}
		case 4:
			if (IsEmptyAQueue(Q))
			{
				printf("the queue is empty\n");
				continue;
			}
			else
			{
				printf("the queue is not empty\n");
				continue;
			}
		case 5:
			if (GetHeadAQueue(Q, e))
			{
				printf("succeeded!\n");
				continue;
			}
			else
			{
				printf("failed!\n");
				continue;
			}
		case 6:
			printf("the length is %d\n", LengthAQueue(Q));
			continue;
		case 7:
			InputData();
			continue;
		case 8:
			if (DeAQueue(Q))
			{
				printf("succeeded!\n");
				continue;
			}
			else
			{
				printf("failed!\n");
				continue;
			}
		case 9:
			ClearAQueue(Q);
			continue;
		case 10:
			if (TraverseAQueue(Q, APrint))
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
		type[Q->rear] = t;
		EnAQueue(Q, &a);
		break;
	case CHAR:;
		char b;
		getchar();
		scanf("%c", &b);
		type[Q->rear] = t;
		EnAQueue(Q, &b);
		break;
	case DOUBLE:;
		double c;
		scanf("%lf", &c);
		type[Q->rear] = t;
		EnAQueue(Q, &c);
		break;
	case STRING:;
		char d[20];
		printf("The max length is 20\n");
		scanf("%s", &d);
		type[Q->rear] = t;
		EnAQueue(Q, &d);
		break;
	}
}
