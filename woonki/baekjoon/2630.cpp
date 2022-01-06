#include <iostream>
#include<stdio.h>
#include<vector>


using namespace std;


int arr[129][129];
int one_count =0, zero_count=0;

void table(int row, int column, int n){
    int cnt = 0;

    for(int i=row; i<row+n; i++){
        for(int j=column; j<column+n;j++){
            if(arr[i][j] == 0) cnt++;
        }
    }
    if(cnt == n*n) {
        zero_count ++;
        return;
    }
    else if (cnt == 0){
        one_count ++;
        return;
    }

    else {
        table(row, column, n / 2);
        table(row + n / 2, column, n / 2);
        table(row, column + n / 2, n / 2);
        table(row + n / 2, column + n / 2, n / 2);
    }
    return;




}

int main() {

    int n;
    cin >> n;

    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }


    table(0,0,n);
    cout << zero_count << '\n' << one_count;
}
