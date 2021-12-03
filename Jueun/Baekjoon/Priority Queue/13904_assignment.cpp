#include <iostream>
#include <queue>
#include <set>
/*
* 우선순위 큐 - 과제(13904)
* https://www.acmicpc.net/problem/13904
*/
int main()
{
    int number = 0;
    std::cin >> number;

    int n1, n2;
    std::priority_queue<std::pair<int, int>> mypq; // 점수 기준 내림차순
    while (number != 0) {
        std::cin >> n1 >> n2;
        mypq.push({ n2, n1 });
        number--;
    }

    /*
    // 출력 확인용
    while (!mypq.empty()) {
        std::cout << mypq.top().first << " " << mypq.top().second << std::endl;
        mypq.pop();
    }
    */

    // solution
    int answer = 0; //, day = 0;
    std::multiset<int> date; // 마감일 오름차순
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