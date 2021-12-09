#include <iostream>
#include <queue>

/*
* 우선순위 큐 - Yonsei TOTO (12018)
* https://www.acmicpc.net/problem/12018
*/

int main()
{
    // n은 전체 과목 수, m은 주어진 마일리지
    int n, m;
    std::cin >> n >> m;

    int count = 0; // 최대로 들을 수 있는 과목 갯수
    int input, maximum, mileage;
    // greater<>: 오름차순
    std::priority_queue<int, std::vector<int>, std::greater<int>> mypq; // 해당 과목에서의 최소 마일리지를 뽑기 위한 queue
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_mileage; // 자리 없는 과목들의 최소 마일리지
    
    while (n != 0)
    {
        std::cin >> input >> maximum;
        
        if (maximum > input) // 자리 남는 과목
        {
            m--; // 마일리지 1만 사용
            count++; // 과목 추가

            for (int i = 0; i < input; i++)
                std::cin >> mileage;   
        }
        else
        {
            for (int i = 0; i < input; i++) {
                std::cin >> mileage;
                mypq.push(mileage);
            }

            int diff = input - maximum;
            for (int i = 0; i < diff; i++)
                mypq.pop();
            int min = mypq.top(); // 신정자 중 가장 작은 마일리지
            min_mileage.push(min);

            // 끝났으면 priority queue 비우기
            while (!mypq.empty())
                mypq.pop();
        }    
        n--;
    }
    
    while (!min_mileage.empty())
    {
        if (m - min_mileage.top() >= 0)
        {
            m -= min_mileage.top();
            min_mileage.pop();
            count++;
        }
        else
            break;
    }

    std::cout << count << std::endl;

    return 0;
}