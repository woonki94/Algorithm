#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset

/*
* 2022.01.03 메모리 초과
* 
* 그래프 이론 - 바이러스
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
	
	// 동적 할당
	int **arr = new int* [computers]; // size Y
	for (int k = 0; k < computers; k++)
	{
		arr[k] = new int[computers]; // size X
		memset(arr[k], 0, sizeof(int) * computers); // 0으로 초기화
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

	// 1번 컴퓨터랑 연결된 컴퓨터 찾기
	std::vector<int> *v = new std::vector<int>();
	
	for(int k=0; k<computers; k++)
	{
		if (arr[0][k] == 1)
		{
			v->push_back(k);
			findConnection(arr, computers, k, v);
		}
	}

	// 겹치는 원소 제거
	sort(v->begin(), v->end());
	v->erase(unique(v->begin(), v->end()), v->end()); // unique: #include <algorithm>

	// answer
	std::cout << v->size() << std::endl;

	/*
	// 행렬 출력
	for (int m = 0; m < computers; m++)
	{
		for (int n = 0; n < computers; n++)
		{
			std::cout << arr[m][n] << " ";
		}
		std::cout << std::endl;
	}

	// 값을 1씩 늘려서 출력 (index 때문에)
	for (int i = 0; i < v->size(); i++)
		std::cout << " " << (v->at(i)) + 1;
	*/

	// 동적 할당 해제
	for (int k = 0; k < computers; k++)
		delete[] arr[k];
	delete[] arr;

	return 0;
}