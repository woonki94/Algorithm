#include <string>
#include <vector>
#include <iostream>
#include <queue>

/*
* ����/ť - ��ɰ���(42586)
* https://programmers.co.kr/learn/courses/30/lessons/42586
*/

std::vector<int> solution2(std::vector<int> progresses, std::vector<int> speeds);
std::vector<int> solution3(std::vector<int> progresses, std::vector<int> speeds);

int main()
{
    std::vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    std::vector<int> speeds = { 1, 1, 1, 1, 1, 1 };
    std::vector<int> answer = solution3(progresses, speeds);

    std::cout << "answer: "; // 1 3 2
    for (int i = 0; i < answer.size(); i++)
        std::cout << answer[i] << " ";

    return 0;
}

std::vector<int> solution3(std::vector<int> progresses, std::vector<int> speeds) {
    /*
    * 3nd solution: 2021.12.05 (queue ���)
    * ��Ȯ��: 100.0
    */
    std::vector<int> answer;

    int index = 0;
    std::queue<int> TakenDays;
    while (index < progresses.size())
    {
        if ((100 - progresses[index]) % speeds[index] == 0)
            TakenDays.push((100 - progresses[index]) / speeds[index]);
        else
            TakenDays.push(((100 - progresses[index]) / speeds[index]) + 1);
        index++;
    }

    while (!TakenDays.empty()) // 7 3 9
    {
        int count = 1; // �Բ� ������ �۾� �� (���� �۾� ����)

        if (TakenDays.size() == 1)
        {
            answer.push_back(count);
            TakenDays.pop();
        }
        else
        {
            int currentWork = TakenDays.front();
            bool check = true;
            while (check && !TakenDays.empty())
            {
                try {
                    TakenDays.pop();
                    if (TakenDays.empty())
                        throw count;
                }
                catch(int ans) {
                    answer.push_back(ans);
                    break;
                }

                if (currentWork >= TakenDays.front())
                    count++;
                else
                {
                    answer.push_back(count);
                    check = false;
                    //break;
                }
            }
        }
    }
    return answer;
}

std::vector<int> solution2(std::vector<int> progresses, std::vector<int> speeds) {
    /*
    * 1st solution: 2021.11.16
    * [���͵�� �ǵ��] speeds�� ���ؼ� TakenDays�� ������ ���� ������ ���� �̿�
    * 
    * 2nd solution: 2021.12.04 (only vector ���)
    * Hidden Test ������ ���� ����.
    */
    std::vector<int> answer;

    int index = 0;
    std::vector<int> TakenDays;
    while (index < progresses.size())
    {
        if ((100 - progresses[index]) % speeds[index] == 0)
            TakenDays.push_back((100 - progresses[index]) / speeds[index]);
        else
            TakenDays.push_back(((100 - progresses[index]) / speeds[index]) + 1);
        index++;
    }

    for (int i = 0; i < TakenDays.size(); i++)
    {
        int count = 1; // �Բ� ������ �۾� �� (���� �۾� ����)

        if (i == progresses.size() - 1)
            answer.push_back(count);
        else
        {
            int currentWork = TakenDays[i];
            index = i;
            while (index < progresses.size())
            {
                ++index;
                if (currentWork >= TakenDays[index])
                    count++;
                else
                {
                    answer.push_back(count);
                    i = (index - 1);
                    break;
                }
            }
        }
    }
    return answer;   
}