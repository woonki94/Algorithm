#include <iostream>
#include <string> // stoi

/*
* 자료 구조 - 스택
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
	// size 함수 호출
	switch (size(topPtr))
	{
		case 0: // 비어있는 경우
			return -1;
			break;

		default:
			return arrPtr[(*topPtr)--];
			break;
	}
}

int empty(int* topPtr)
{
	// size 함수 호출
	switch (size(topPtr))
	{
	case 0: // 비어있는 경우
		return 1;
		//break; // 생략?

	default:
		return 0;
		//break;
	}
}

int topp(int* arrPtr, int* topPtr)
{
	// size 함수 호출
	switch (size(topPtr))
	{
	case 0: // 비어있는 경우
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
		//std::cin >> command; // 띄어쓰기 미포함
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