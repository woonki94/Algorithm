#include <vector>
#include <unordered_set>
using namespace std;

int NN(int num, int count){
    int number = num;
    for(int i=0; i<count-1; i++){
        number = number*10+num;
    }
    return number;
}


int solution(int N, int number) {
    int answer=0;
    
    vector<unordered_set<int>> v(9);
    
    v[1].insert(N);
    
    for(int i=2; i<=8; i++){
        //int nn = NN(N, i);
        //v[i].insert(nn);
        for(int j=1; j<i; j++){
            
            int k = i - j;
            
            for(int x : v[j]){
                for(int y : v[k]){
                    v[i].insert(x+y);
                    if(x>y) v[i].insert(x-y);
                    v[i].insert(x*y);
                    if(x>=y) v[i].insert(x/y);
                    
                }
            }
        }
        int nn = NN(N, i);
        v[i].insert(nn);
        
        
    }
    //printf("%d", NN(5,3));
    
    for(int i=1; i<=8; i++){
        if(v[i].count(number)){
            answer = i;
            break;
        }
    }
    if(answer == 0)
        answer = -1;
    

    return answer;
    
    
}