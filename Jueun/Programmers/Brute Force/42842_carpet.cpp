#include <iostream>
#include <string>
#include <vector>
#include <map>


/*
* 2022.01.03 
* 
* 완전 탐색 - 카펫
* https://programmers.co.kr/learn/courses/30/lessons/42842?language=cpp
*/

void gcd(int number, std::map<int, int>* ptr)
{
    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
            ptr->insert(std::pair<int, int>(i, number / i));
    }
}

bool checkSize(int size, int yellow_h, int yellow_w)
{
    /*
    * yellow=24, brown=24
    * map = {[1, 24], [2, 12], [3, 8], [4, 6], [6, 4], [8, 3], [12, 2], [24, 1]}
    */

    if ((yellow_w + 2) * (yellow_h + 2) == size)
        return true;
    else
        return false;
}

std::vector<int> solution(int brown, int yellow) {
    std::vector<int> answer; // 가로, 세로 순서

    std::map<int, int> m;
    std::map<int, int>* ptr = &m;
    gcd(yellow, ptr);

    int size = brown + yellow;
    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        if (checkSize(size, it->first, it->second))
        {
            int h = it->first + 2;
            int w = it->second + 2;

            answer.push_back(w);
            answer.push_back(h);
            break;
        } 
    }
   
    return answer;
}

int main()
{
    int brown = 24;
    int yellow = 24;

    std::vector<int> v = solution(brown, yellow);
    
    for (int i = 0; i < v.size(); i++)
        std::cout << v.at(i) << " ";

    return 0;
}