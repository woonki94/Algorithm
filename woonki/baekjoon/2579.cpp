#include<iostream>

using namespace std;
int main(){
    int n;
    int arr[301]={0,};
    int answer[301] = {0,};
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    answer[1] = arr[1];
    answer[2] = arr[1]+ arr[2];
    for(int i=3; i<= n; i++) {
        answer[i] = max(arr[i - 1] + answer[i - 3] + arr[i], answer[i - 2] + arr[i]);
    }

    cout << answer[n];

}
