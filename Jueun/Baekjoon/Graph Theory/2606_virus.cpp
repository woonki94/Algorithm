#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset

/*
* 2022.01.03 �޸� �ʰ�
* 
* �׷��� �̷� - ���̷���
* https://www.acmicpc.net/problem/2606
*/

void findConnection(int** ptr, int arrSize, int k, std::vector<int>* v)
{
	for (int index = 0; index < arrSize; index++)
	{
		if (ptr[k][index] == 1)
		{
			v->push_back(index);
			findConnection(ptr, arrSize, index, v);			
		}
	}
}

int main()
{
	int computers, connections;
	std::cin >> computers >> connections;
	
	// ���� �Ҵ�
	int **arr = new int* [computers]; // size Y
	for (int k = 0; k < computers; k++)
	{
		arr[k] = new int[computers]; // size X
		memset(arr[k], 0, sizeof(int) * computers); // 0���� �ʱ�ȭ
	}

	int i = 0;
	int num1, num2;
	while (i != connections)
	{
		std::cin >> num1 >> num2;
		
		arr[num1 - 1][num2 - 1] = 1;
		//arr[num2 - 1][num1 - 1] = 1;

		i++;
	}

	// 1�� ��ǻ�Ͷ� ����� ��ǻ�� ã��
	std::vector<int> *v = new std::vector<int>();
	
	for(int k=0; k<computers; k++)
	{
		if (arr[0][k] == 1)
		{
			v->push_back(k);
			findConnection(arr, computers, k, v);
		}
	}

	// ��ġ�� ���� ����
	sort(v->begin(), v->end());
	v->erase(unique(v->begin(), v->end()), v->end()); // unique: #include <algorithm>

	// answer
	std::cout << v->size() << std::endl;

	/*
	// ��� ���
	for (int m = 0; m < computers; m++)
	{
		for (int n = 0; n < computers; n++)
		{
			std::cout << arr[m][n] << " ";
		}
		std::cout << std::endl;
	}

	// ���� 1�� �÷��� ��� (index ������)
	for (int i = 0; i < v->size(); i++)
		std::cout << " " << (v->at(i)) + 1;
	*/

	// ���� �Ҵ� ����
	for (int k = 0; k < computers; k++)
		delete[] arr[k];
	delete[] arr;

	return 0;
}