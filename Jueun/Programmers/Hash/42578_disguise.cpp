#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 해시 - 위장
// https://programmers.co.kr/learn/courses/30/lessons/42578

int solution2(vector<vector<string>> clothes);

int main()
{
    std::vector<std::vector<string>> clothes = { {"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"} };
    std::cout << "answer: " << solution2(clothes) << std::endl;

}

int solution2(vector<vector<string>> clothes) {
    /*
    * 2nd solution: 2021/11/24
    *
    * 100.0 / 100.0
    * 정확성 100.0점
    *
    * 1st solution(2021/11/01) 때는 STL 종류에 익숙하지 않아서 아예 엉뚱한 길로 헤맸다. (다 풀지 못해서 올리지 않았음)
      2nd solution에서는 구조 자체를 바꿔서 STL map을 사용.
    */
    int answer = 0;

    // map의 key에는 [의상 종류]를, value에는 [의상 종류]에 해당하는 옷의 갯수
    map<std::string, int> m;

    for (int i = 0; i < clothes.size(); i++)
    {
        // 해당 key가 존재하면 1을, 존재하지 않으면 0을 반환
        int is_exist = m.count(clothes[i][1]);

        if (is_exist == true) // map에 이미 [의상 종류]가 존재하는 경우
        {
            int temp = m[clothes[i][1]];
            m[clothes[i][1]] = ++temp;
        }
        else if (is_exist == false) // 없는 경우
            m.insert(pair<std::string, int>(clothes[i][1], 1));
    }

    auto it = m.begin();
    /*
    // 출력 (확인용)
    for (it = m.begin(); it != m.end(); it++)
        std::cout << it->first << ":" << it->second << " ";
    */
    if (m.size() == 1) // [의상 종류]가 1개인 경우
    {
        it = m.begin();
        answer = (*it).second;
        return answer;
    }
    else // [의상 종류]가 2개 이상인 경우
    {
        int answer = 1;

        for (it = m.begin(); it != m.end(); it++)
            answer *= (((*it).second) + 1); // +1: 해당 [의상 종류]를 입지 않는 경우까지 계산

        --answer; // 어떠한 [의상 종류]도 입지 않은 케이스를 제외
        return answer;
    }
}