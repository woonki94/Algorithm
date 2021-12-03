#include <iostream>
#include <queue>
#include <set>
/*
* �켱���� ť - ����(13904)
* https://www.acmicpc.net/problem/13904
*/
int main()
{
    int number = 0;
    std::cin >> number;

    int n1, n2;
    std::priority_queue<std::pair<int, int>> mypq; // ���� ���� ��������
    while (number != 0) {
        std::cin >> n1 >> n2;
        mypq.push({ n2, n1 });
        number--;
    }

    /*
    // ��� Ȯ�ο�
    while (!mypq.empty()) {
        std::cout << mypq.top().first << " " << mypq.top().second << std::endl;
        mypq.pop();
    }
    */

    // solution
    int answer = 0; //, day = 0;
    std::multiset<int> date; // ������ ��������
    std::multiset<int>::iterator it;
    while (!mypq.empty()) {
        date.insert(mypq.top().second);

        int index = 1;
        it = date.begin();
        bool check = true;
        while (it != date.end()) {
            if (*it >= index) {
                index++;
                it++;
            }
            else {
                check = false;
                break;
            }
        }

        if (check == true) {
            answer += mypq.top().first;
            mypq.pop();
        }
        else {
            date.erase(mypq.top().second);
            mypq.pop();
        }
    }

    std::cout << answer;
    return 0;
}