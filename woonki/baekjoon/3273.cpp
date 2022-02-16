#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,x;
    int cnt = 0, left = 0, right = 0;

    cin >> n;
    int arr[100000]={0,};
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> x;

    sort(arr, arr+n);


    right = n-1;
    while(left < right){
        int tmp = arr[left] + arr[right];
        if(tmp == x){
            cnt++;
            left++;
            right--;
        }
        else if(tmp < x) left++;
        else right--;
    }

    cout << cnt;
}
