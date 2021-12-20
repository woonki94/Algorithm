#include <string>
#include <vector>

using namespace std;

int func(int index, vector<int> ans){
    int size = ans.size();
    
    index%=size;
    
    return ans[index];
    
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int n = answers.size();
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    vector<int> one ={1,2,3,4,5};
    vector<int> two={2,1,2,3,2,4,2,5};
    vector<int> three = {3,3,1,1,2,2,4,4,5,5,};
    
    for(int i=0; i<n; i++){
        if(func(i, one) == answers[i])
            cnt1++;
        if(func(i, two) == answers[i])
            cnt2++;
        if(func(i, three) == answers[i])
            cnt3++;
        
    }
    //cnt1 =1;
    //answer.push_back(cnt1);
    //else if(cnt2>cnt1&&cnt2>cnt3)
    //    answer.push_back(cnt2);
    if(cnt1>cnt2){
        if(cnt1==cnt3){
            answer.push_back(1);
            answer.push_back(3);
        }
        else if(cnt3>cnt1)
            answer.push_back(3);
        else answer.push_back(1);
    }
    else if(cnt2>cnt1){
        if(cnt2==cnt3){
            answer.push_back(2);
            answer.push_back(3);
        }
        else if(cnt3>cnt2)
            answer.push_back(3);
        else answer.push_back(2);
    }
   
    
    return answer;
}