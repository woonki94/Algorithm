
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, answer = 0;
    cin >> n;
    int arr[501][501]={0,};


    for(int i=1; i<=n; i++){
        for(int j=1; j<=i;j++){
            cin >> arr[i][j];
            arr[i][j] += max(arr[i-1][j], arr[i-1][j-1]);
        }
    }
    for(int i= 1 ; i<=n; i++){
        answer = max(answer, arr[n][i]);
    }

    cout << answer;

}
