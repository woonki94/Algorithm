#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n;
    cin >> n;

    priority_queue<int> pq;

    while(n--){
        int num;
        cin >> num;
        if(num ==0){
            if(pq.size() == 0) cout << 0;
            else{
                cout << pq.top();
                pq.pop();
            }
            cout << "\n";
        }
        else pq.push(num);
    }
}
