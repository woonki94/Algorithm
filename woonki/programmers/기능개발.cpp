#include <string>
#include <vector>
#include<stack>
#include<queue>
#include<stdio.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    //완료되기까지 걸리는 시간을 구해서 큐에 넣어서 
    //(100-30)/30 = 700/30 = 23.3333
    queue <int> q;
    int tmp=0;
    
    for(int i=0; i<progresses.size(); i++){
        tmp = ((100-progresses[i])*10/speeds[i]+9)/10; // 소수점있으면 올림
        q.push(tmp);
    }
    
    for(int i=0; !q.empty() ;i++){
        int cnt=1;
        int tmp = q.front();
        q.pop();
        while(tmp>=q.front()&&!q.empty()){
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
        
    }
    return answer;
}