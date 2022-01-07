#include <string>
#include <vector>

using namespace std;

int cnt=0;

void DFS(int L, int size, int target, vector<int> numbers, vector<int> ch){
    if(L==size){
        int sum =0;
        for(int i=0; i<size; i++){
            sum+=ch[i];
        }
        if(sum == target) cnt++;
    }
    else{
        ch[L] = numbers[L];
        DFS(L+1,size, target, numbers, ch);
        ch[L] = -numbers[L];
        DFS(L+1, size, target, numbers, ch);
    }
    
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int size = numbers.size();
    vector<int> ch(size,0);
    
    DFS(0,size, target, numbers, ch);
    
    answer = cnt;
    
    return answer;
}