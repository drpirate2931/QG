#include "DuLinkedList.h"

bool IsInt(char _data[])
{
	for (int i = 0; _data[i] != '\0'; i++)
	{
		if (!isdigit(_data[i]))
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
	std::cout << "2.Insert a node at head" << std::endl;
	std::cout << "3.Delete a node at a specific position" << std::endl;
	std::cout << "4.Print the list" << std::endl;
	std::cout << "5.Quit" << std::endl;
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
			std::cout << "Please input the value : ";

			while (std::cin >> _data && !IsInt(_data))
			{
				std::cout << "Please input the correct form : ";
			}

			list.InsertAtHead(atoi(_data));
			continue;
		case 3:
			std::cout << "Please input the position of the node (starts from 1) : ";

			while (std::cin >> deletePosition && !IsInt(deletePosition))
			{
				std::cout << "Please input the correct form : ";
			}
			
			list.DeleteNode(atoi(deletePosition));
			continue;
		case 4:
			list.PrintList();
			continue;
		case 5:
			return 0;
		default:
			continue;
		}

		return 0;
	}
}