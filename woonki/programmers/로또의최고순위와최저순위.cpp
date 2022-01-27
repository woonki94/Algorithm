#include <string>
#include <vector>

using namespace std;
vector<int> answer;

void getanswer(int n){
    switch(n){
        case 6: answer.push_back(1); break;
        case 5: answer.push_back(2); break;
        case 4: answer.push_back(3); break;
        case 3: answer.push_back(4); break;
        case 2: answer.push_back(5); break;
        default: answer.push_back(6); break;
    
    }
    
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    //vector<int> answer;
     
    int match_zero=0;
    int match_lotto = 0;
    
    int max, min;
    
    for(int i=0; i<6; i++){
        if(lottos[i]==0) match_zero++;
        
    }
    for(int i=0; i<6; i++){
        for(int j=0; j<6;j++){
            if(lottos[i] == win_nums[j]) {
                match_lotto++;
                break;
            }
        }
    }
    max = match_zero+match_lotto;
    min = match_lotto;
    
    getanswer(max);
    getanswer(min);
    
    
    return answer;
}
