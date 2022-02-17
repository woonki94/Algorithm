
#include<iostream>
using namespace std;

int main(){
    int n, s;
    int arr[100000]={0,};
    int left=0, right=0, sum =0, min = 2147383647;

    cin >> n >> s;

    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }



    while(left <= right){
        if(sum >= s){
            if(min > (right-left)){
                min = right - left;
            }
            sum -= arr[left++];
        }
        else if(right == n) break;
        else sum += arr[right++];
    }
    if(min == 2147383647) cout << 0;
    else
        cout << min;






}



