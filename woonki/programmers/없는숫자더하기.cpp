#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<int> result(10,0);
    for(int i=0; i<numbers.size(); i++){
        result[numbers[i]]++;
    }
    
    for(int i=0; i<result.size(); i++){
        if(result[i]== 0 ){
            answer+= i;
        }
    }
    
    return answer;
}
