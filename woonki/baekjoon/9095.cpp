#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

//1,2,3 의 합으로 n을 만들어라
//dp[1] = 1
//dp[2] = 1
//dp[3] = 1+1+1 1+2 2+1 3
// 기본형 -> dp[n] = dp[n-1] + dp[n-2] +dp[n-3];
int main(){
  ios_base::sync_with_stdio(false);
  int n;
  int x;
  vector<int> answer;
  cin>>n;
  
  while(n--){
    cin>>x;
    int dp[11] ={0,};
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i= 4; i<= x; i++){
      dp[i] = dp[i-1]+dp[i-2]+ dp[i-3];
    }
  
    answer.push_back(dp[x]);
  }
  for(int ans : answer){
    cout << ans <<'\n';
  }

}