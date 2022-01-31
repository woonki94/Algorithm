#include <string>
#include <vector>
#include<iostream>
#include<cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    while(n >= 3){
        v.push_back(n%3);
        n/=3;
    }
    v.push_back(n%3);

    for(int i=0; i<v.size(); i++){
        int tmp = v.size() -1 -i;
        answer += v[i] * pow(3,tmp);
        
    }
    return answer;
}









