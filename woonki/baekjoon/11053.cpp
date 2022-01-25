#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[1001]={0,};
    int dp[1001]={0,};
    dp[1] = 1;

    for(int i=1;i<=n; i++){
        cin >> arr[i];
    }

    for(int i=2; i<=n; i++){
        int val =0;
        for(int j= i-1; j>=1; j-- ){
            if(arr[i] >  arr[j] && dp[j] > val){
                val = dp[j];
            }
        }
        dp[i] = val+1;

    }
    int tmp =-1;
    for(int i=1 ; i<=n; i++){
        if(tmp<dp[i]) tmp = dp[i];
    }

    cout << tmp;

}
