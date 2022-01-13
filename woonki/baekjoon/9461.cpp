#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;
int main(){
    int n;
    long long answer[101] = {0,1,1,1,2,2,};
    cin >> n;
    vector<int> v(n,0);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }


    for(int i=6; i <= *max_element(v.begin(), v.end()); i++){
        answer[i] = answer[i-1]+ answer[i-5];
    }

    for(int i=0; i<n; i++){
        int tmp = v[i];
        cout << answer[tmp]<< "\n";
    }






}
