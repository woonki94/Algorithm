#include <string>
#include <vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> stu(n , 1);
    
    for(int i: lost) stu[i-1] -=1;
    for(int i:reserve) stu[i-1]+=1;
    
    for(int i=0; i<stu.size();i++){
        if(stu[i]==0){
            if(stu[i-1]==2){
                stu[i] =1;
                stu[i-1] =1;
            }
            else if(stu[i+1]==2){
                stu[i] =1;
                stu[i+1] =1;
            }
            
            
        }
        
    }
    
    for(int i=0; i<stu.size(); i++){
        if(stu[i]>=1) answer++;
        
    }
    
    return answer;
}