#include <string>
#include <vector>
#include<queue>
//#include<utility>
using namespace std;


int find_max(queue<int> q){
    int max=0;
    vector<int> tmp;
    for(int i=0; !q.empty(); i++){
        tmp.push_back(q.front());
    }
    for(int i=0 ; i<tmp.size(); i++){
        if(max < tmp[i]) max = tmp[i];
    }
    
    return max;
    
}

int solution(vector<int> priorities, int location) {
    
    int answer = 0;
    //int max = find_max(priorities);
    
    int loc = location;
    int cnt=1;
    int size = priorities.size()-1;
    
    priority_queue<int> pq;
    queue<int> q;
    
    for(int i=0; i<priorities.size(); i++){
        pq.push(priorities[i]);
        q.push(priorities[i]);
    }
    
    
    /*
    for(int i=0; !pq.empty(); i++){
        printf("%d", pq.top());
        pq.pop();
            
            
    }
    */
    //printf("%d", max);
      
   // q.push(q.front());
    //printf("%d", q.back());
    
    
    while(!q.empty()){
        
        int max = pq.top();
        if(q.front()!= max){
            q.push(q.front());
            q.pop();
            if(loc==0) loc = size;
            else loc--;
        }
        else if(q.front() == max){
            if(loc ==0) break;
            else{
                q.pop(); 
                pq.pop();
                cnt++;
                if(loc==0)loc = size;
             
            else loc--;
            size--;
            }
        }
        
    }
    
    
    answer = cnt;
    
    return answer;
}
