#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// �ؽ� - ����
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
    * ��Ȯ�� 100.0��
    *
    * 1st solution(2021/11/01) ���� STL ������ �ͼ����� �ʾƼ� �ƿ� ������ ��� ��̴�. (�� Ǯ�� ���ؼ� �ø��� �ʾ���)
      2nd solution������ ���� ��ü�� �ٲ㼭 STL map�� ���.
    */
    int answer = 0;

    // map�� key���� [�ǻ� ����]��, value���� [�ǻ� ����]�� �ش��ϴ� ���� ����
    map<std::string, int> m;

    for (int i = 0; i < clothes.size(); i++)
    {
        // �ش� key�� �����ϸ� 1��, �������� ������ 0�� ��ȯ
        int is_exist = m.count(clothes[i][1]);

        if (is_exist == true) // map�� �̹� [�ǻ� ����]�� �����ϴ� ���
        {
            int temp = m[clothes[i][1]];
            m[clothes[i][1]] = ++temp;
        }
        else if (is_exist == false) // ���� ���
            m.insert(pair<std::string, int>(clothes[i][1], 1));
    }

    auto it = m.begin();
    /*
    // ��� (Ȯ�ο�)
    for (it = m.begin(); it != m.end(); it++)
        std::cout << it->first << ":" << it->second << " ";
    */
    if (m.size() == 1) // [�ǻ� ����]�� 1���� ���
    {
        it = m.begin();
        answer = (*it).second;
        return answer;
    }
    else // [�ǻ� ����]�� 2�� �̻��� ���
    {
        int answer = 1;

        for (it = m.begin(); it != m.end(); it++)
            answer *= (((*it).second) + 1); // +1: �ش� [�ǻ� ����]�� ���� �ʴ� ������ ���

        --answer; // ��� [�ǻ� ����]�� ���� ���� ���̽��� ����
        return answer;
    }
}