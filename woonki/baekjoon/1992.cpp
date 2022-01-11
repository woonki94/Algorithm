#include <iostream>
#include<stdio.h>
#include<vector>


using namespace std;



string arr[65];
string answer="";

void table(int row, int column, int n){
    int cnt = 0;

    for(int i=row; i<row+n; i++){
        for(int j=column; j<column+n;j++){
            if(arr[i][j] == '0') cnt++;
        }
    }

    if(cnt == n*n) {

        answer += "0";
        return;
    }
    else if (cnt == 0){

        answer+= "1";
        return;
    }

    else {
        answer+= "(";
        table(row, column, n / 2);

        table(row, column + n / 2, n / 2);

        table(row + n / 2, column, n / 2);


        table(row + n / 2, column + n / 2, n / 2);
        answer+= ")";
    }
    return;




}

int main() {

    int n;
    cin >> n;

    for(int i=0; i<n;i++){
            cin >> arr[i];

    }








    table(0,0,n);

    cout<<answer;
}

