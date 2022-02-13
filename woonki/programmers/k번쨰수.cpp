#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer(commands.size(),0);

    for(int i=0; i<commands.size(); i++){ 
      int n =commands[i][1]-commands[i][0]+1;
      vector<int> tmp(n,0);
      int k=0;
        
      for(int j=commands[i][0]-1; j<commands[i][1]; j++){
        tmp[k++] = array[j];
      }
      sort(tmp.begin(), tmp.end());
      answer[i] = tmp[commands[i][2]-1];  
    }
    return answer;
}
