//
// Created by 김운기 on 2022/01/20.
//


#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long answer[10010]= {0,};
    long long arr[10010]= {0,};

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    answer[1] = arr[1];
    answer[2] = arr[1]+arr[2];
    long long tmp = max(arr[1]+arr[2], arr[1]+arr[3]);
    answer[3] = max(tmp , arr[2]+arr[3]);

    for(int i=4; i<=n; i++){
        long long tmp = max(arr[i - 1] + answer[i - 3] + arr[i], answer[i - 2] + arr[i]);
        answer[i] = max(tmp , answer[i-1]);//arr[i-1]+arr[i-2]+answer[i-4]);
    }

    cout << answer[n];


}


