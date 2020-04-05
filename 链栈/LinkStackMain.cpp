#include "LinkStack.h"

typedef int ElemType;

void menu()
{
	puts("\n");
	cout << "Please choose a function:" << endl;
	cout << "1.Judge if the stack is empty" << endl;
	cout << "2.Get the top data of the stack" << endl;
	cout << "3.Push a data into the stack" << endl;
	cout << "4.Pop the top data out of the stack" << endl;
	cout << "5.Get the length of the stack" << endl;
	cout << "6.Clear the stack" << endl;
	cout << "7.Print the stack" << endl;
	cout << "8.Quit" << endl;
	puts("\n");
}

int main()
{
	system("color F0");
	LinkStack<int> stack;
	int ch;
	int length;
	ElemType data;
	ElemType topVal;
	
	while (true)
	{
		menu();
		cin >> ch;
		switch (ch)
		{
		case 1:
			if (stack.isEmptyStack())
			{
				cout << "The stack is empty" << endl;
			}
			else
			{
				cout << "The stack is not empty" << endl;
			}
			continue;
		case 2:
			if (stack.getTopLStack(&topVal))
			{
				cout << "Success!" << endl;
				cout << "The value is " << topVal << endl;
			}
			else
			{
				cout << "Fail!" << endl;
			}
			continue;
		case 3:
			cout << "Please input the value: ";
			cin >> data;
			if (stack.pushLStack(data))
			{
				cout << "Success!" << endl;
			}
			else
			{
				cout << "Fail!" << endl;
			}
			continue;
		case 4:
			if (stack.popLStack(&topVal))
			{
				cout << "Success!" << endl;
				cout << "The value is " << topVal << endl;
			}
			else
			{
				cout << "Fail!" << endl;
			}
			continue;
		case 5:
			if (stack.LStackLength(&length))
			{
				cout << "The length of the stack is " << length << endl;
				
			}
			else
			{
				cout << "The stack has no value" << endl;
			}
			continue;
		case 6:
			if (stack.clearLStack())
			{
				cout << "Success!" << endl;
			}
			else
			{
				cout << "Fail!" << endl;
			}
			continue;
		case 7:
			stack.printLStack();
			continue;
		case 8:
			return 0;
		default:
			continue;
		}
	}

	return 0;
}