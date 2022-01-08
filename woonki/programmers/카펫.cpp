#include <string>
#include <vector>
#include<stdio.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> h;
    vector<int> l;
   
    int size = brown+yellow;
    
    
    for(int i=1; i<size/2; i++){
        int h_tmp = i;
        int l_tmp = size/i;
        if(size%i==0&& (h_tmp<=l_tmp)){
            h.push_back(h_tmp);
            l.push_back(l_tmp);
            
        }
    }
    
    
    for(int i=0; i<h.size();i++){
        printf("%d\t%d", h[i], l[i]);
        printf("\n");
    }
    
    for(int i=0; i<h.size(); i++){
        if((h[i]*2+l[i]*2-4)== brown){
            answer.push_back(l[i]);
            answer.push_back(h[i]);
            break;
        }
            
    }    
    
    
    return answer;
}
