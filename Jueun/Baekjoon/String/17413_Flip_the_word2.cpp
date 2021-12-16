#include <iostream>
#include <string>

#define MAX 1000001 // +1: Null

/*
* ���ڿ� - �ܾ� ������2
* https://www.acmicpc.net/problem/17413
*/

int main()
{
	char str[MAX];
	std::cin.getline(str, MAX, '\n');

	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ') // ����
		{
			std::cout << str[i]; // ���� �״�� ���
			i++;
		}
		else if (str[i] == '<')
		{
			std::cout << str[i]; // <
			i++;
			while (1)  // >�� ���� ������
			{
				std::cout << str[i];
				if (str[i] == '>')
					break;
				i++;
			}
			i++;
		}
		else if ((str[i] >= 48 && str[i] <= 57) || // 0~9 ASCII
			(str[i] >= 97 && str[i] <= 122)) // �ҹ��� a~z ASCII
		{
			int start = i - 1;
			while ((str[i] != ' ') && (str[i] != '<') && (str[i] != '\0')) // �����̳� ���� �ܾ� ���� ������
			{
				i++;
			}
			int end = i - 1;
			
			while (end != start)
			{
				std::cout << str[end];
				end--;
			}
		}
		
		//i++;
	}
	

	return 0;
}