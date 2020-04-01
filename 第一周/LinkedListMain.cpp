#include "LinkedList.h"

bool IsInt(char s[])
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (!isdigit(s[i]))
		{
			return false;
		}
	}

	return true;
}

void Menu()
{
	std::cout << "Welcome to a simple LinkedList test" << std::endl;
	std::cout << "Please choose a function:" << std::endl;
	std::cout << "1.Insert a node at tail" << std::endl;
	std::cout << "2.Destroy the list" << std::endl;
	std::cout << "3.Delete a node at a specific position" << std::endl;
	std::cout << "4.Search the list by a value" << std::endl;
	std::cout << "5.Reverse te list" << std::endl;
	std::cout << "6.Judge if there is a loop in the list" << std::endl;
	std::cout << "7.Reverse the nodes in pairs" << std::endl;
	std::cout << "8.Find the middle position of the list" << std::endl;
	std::cout << "9.Print the list" << std::endl;
	std::cout << "10.Quit" << std::endl;
}

int main()
{
	system("color F0");
	LinkedList list;
	while (true)
	{
		Menu();
		int ch;
		bool jug;
		char _data[1024];
		char deletePosition[1024];
		char value[1024];
		std::cin >> ch;

		switch (ch)
		{
		case 1:
			std::cout << "Please input the value : ";
			
			while (std::cin >> _data && !IsInt(_data))
			{
				std::cout << "Please input the correct form : ";
			}
			
			list.InsertAtTail(atoi(_data));
			continue;
		case 2:
			list.DestroyList();
			continue;
		case 3:
			std::cout << "Please input the position of the node (starts from 1): ";
			while (std::cin >> deletePosition && !IsInt(deletePosition))
			{
				std::cout << "Please input the correct form : ";
			}
			
			list.DeleteNode(atoi(deletePosition));
			continue;
		case 4:
			
			std::cout << "Please input the value you want to search for : ";
			while (std::cin >> value && !IsInt(value))
			{
				std::cout << "Please input the correct form : ";
			}
			
			list.SearchList(atoi(value));
			continue;
		case 5:
			list.ReverseList();
			continue;
		case 6:
			jug = list.IsLoopList();
			
			if (jug)
			{
				std::cout << "The list has a loop" << std::endl;
				puts("\n");
				continue;
			}
			else
			{
				std::cout << "The list has no loop" << std::endl;
				puts("\n");
				continue;
			}
		case 7:
			list.ReverseEvenList();
			continue;
		case 8:
			list.FindMidNode();
			continue;
		case 9:
			list.PrintList();
			continue;
		case 10:
			return 0;
		default:
			continue;
		}
	}

	return 0;
}