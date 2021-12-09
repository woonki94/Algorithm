#include <iostream>
#include <queue>

/*
* �켱���� ť - Yonsei TOTO (12018)
* https://www.acmicpc.net/problem/12018
*/

int main()
{
    // n�� ��ü ���� ��, m�� �־��� ���ϸ���
    int n, m;
    std::cin >> n >> m;

    int count = 0; // �ִ�� ���� �� �ִ� ���� ����
    int input, maximum, mileage;
    // greater<>: ��������
    std::priority_queue<int, std::vector<int>, std::greater<int>> mypq; // �ش� ���񿡼��� �ּ� ���ϸ����� �̱� ���� queue
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_mileage; // �ڸ� ���� ������� �ּ� ���ϸ���
    
    while (n != 0)
    {
        std::cin >> input >> maximum;
        
        if (maximum > input) // �ڸ� ���� ����
        {
            m--; // ���ϸ��� 1�� ���
            count++; // ���� �߰�

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
            int min = mypq.top(); // ������ �� ���� ���� ���ϸ���
            min_mileage.push(min);

            // �������� priority queue ����
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