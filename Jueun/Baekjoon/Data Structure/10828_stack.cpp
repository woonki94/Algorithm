#include <iostream>
#include <string> // stoi

/*
* �ڷ� ���� - ����
* https://www.acmicpc.net/problem/10828
*/

int size(int* topPtr)
{
	int size = 1 + *topPtr;
	return size;
}

void push(int* arrPtr, int num, int* topPtr)
{
	arrPtr[++(*topPtr)] = num;
}

int pop(int* arrPtr, int* topPtr)
{
	// size �Լ� ȣ��
	switch (size(topPtr))
	{
		case 0: // ����ִ� ���
			return -1;
			break;

		default:
			return arrPtr[(*topPtr)--];
			break;
	}
}

int empty(int* topPtr)
{
	// size �Լ� ȣ��
	switch (size(topPtr))
	{
	case 0: // ����ִ� ���
		return 1;
		//break; // ����?

	default:
		return 0;
		//break;
	}
}

int topp(int* arrPtr, int* topPtr)
{
	// size �Լ� ȣ��
	switch (size(topPtr))
	{
	case 0: // ����ִ� ���
		return -1;

	default:
		return arrPtr[*topPtr];
	}
}

int main()
{
	int s[10000] = { 0, };
	int top = -1;

	int *arrPtr = s;
	int *topPtr = &top;
	
	int iteration;
	std::cin >> iteration;

	std::string command;
	while (iteration != -1)
	{
		//std::cin >> command; // ���� ������
		getline(std::cin, command);

		if (command.find("push") != -1)
		{
			int num = stoi(command.substr(5, command.length()));
			push(arrPtr, num, topPtr);
		}
		else if (command.find("pop") != -1)
		{
			std::cout << pop(arrPtr, topPtr) << std::endl;
		}
		else if (command.find("size") != -1)
		{
			std::cout << size(topPtr) << std::endl;
		}
		else if (command.find("empty") != -1)
		{
			std::cout << empty(topPtr) << std::endl;
		}
		else if (command.find("top") != -1)
		{
			std::cout << topp(arrPtr, topPtr) << std::endl;
		}

		iteration--;
	}

	return 0;
}