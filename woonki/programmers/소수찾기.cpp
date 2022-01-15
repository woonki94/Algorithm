#include <string>
#include <vector>
#include<algorithm>
#include<set>

using namespace std;


bool check(int num) {
	if (num == 0 || num == 1)
		return false;

	for (int i = 2; i<num; i++) {
		if (num%i == 0)
			return false;
	}
	return true;
}


int solution(string numbers) {
    int answer = 0;
    
    set<int> tmp;
    int n=0;
    
    sort(numbers.begin(), numbers.end());
    
    do{
        for(int i=0; i<numbers.length(); i++){
            n = stoi(numbers.substr(0,i+1));
            
            if(check(n)) tmp.insert(n);
        }
        
        
    }while(next_permutation(numbers.begin(),numbers.end()));
    
    answer = tmp.size();
    
    
    
    return answer;
}
