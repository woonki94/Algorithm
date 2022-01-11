#include <iostream>
#include <vector>


using namespace std;

// 00 , 1

// N=1 : 1
// N=2 : 00 , 11
// N=3 : 100, 001, 111
// N =4 : 0011, 0000, 1001, 1100, 1111
// N=5 : 00111, 0001, 10011, 11001, 11111
//       10011 10000, 1001, 1100, 1111
//       00111, 00100,

int main() {

    long long v[1000001];
    int n;
    cin >> n;
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;


    for(int i=3; i<=n; i++){

        v[i] = (v[i-2] + v[i-1])%15746;
    }


    cout << v[n];





}


