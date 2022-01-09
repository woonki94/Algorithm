#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int weight =0;
    sort(people.begin(), people.end());
    int start=0;
    int end = people.size()-1;
    
    while(end>=start){
        
        weight = people[start]+ people[end];
        
        if(weight > limit){
            end --;
            answer ++;
        }
        else if(weight <= limit){
            start++;
            end--;
            answer++;
        }
        
        
            
        
    }
    
    return answer;
}
