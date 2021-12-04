#include <string>
#include <vector>
#include <iostream>

/*
* 해시 - 기능개발(42586)
* https://programmers.co.kr/learn/courses/30/lessons/42586
*/

std::vector<int> solution2(std::vector<int> progresses, std::vector<int> speeds);

int main()
{
    std::vector<int> progresses = { 93, 30, 55 };
    std::vector<int> speeds = { 1, 30, 5 };
    std::vector<int> answer = solution2(progresses, speeds);

    std::cout << "answer: ";
    for (int i = 0; i < answer.size(); i++)
        std::cout << answer[i] << " ";

    return 0;
}

std::vector<int> solution2(std::vector<int> progresses, std::vector<int> speeds) {
    /*
    * 1st solution: 2021.11.16
    * [스터디원 피드백] speeds를 더해서 TakenDays를 구하지 말고 나누기 연산 이용
    * 
    * 2nd solution: 2021.12.04
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
        int count = 1; // 함께 배포할 작업 수 (현재 작업 포함)

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