#define MOD 1000
#include <iostream>
#include <vector>
using namespace std;
int num;

vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> result(num, vector<int>(num, 0));
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            for (int k = 0; k < num; k++) {
                result[i][j] += (a[i][k] * b[k][j]);
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

vector<vector<int>> pow(vector<vector<int>> &a, vector<vector<int>> &v, long long square) {
    if (square == 1) return v;
    vector<vector<int>> temp(num, vector<int>(num, 0));
    if (square % 2 == 0) {
        temp = pow(a, v, square / 2);
        return mul(temp, temp);
    }
    temp = pow(a, v, square - 1);
    return mul(temp, a);
}

int main() {
    long long square;
    cin >> num >> square;
    vector<vector<int>> v(num, vector<int>(num, 0));
    vector<vector<int>> arr(num, vector<int>(num, 0));
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++) {
            cin >> arr[i][j];
            v[i][j] = arr[i][j];
        }
    v = pow(arr,v,square);
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++)
            cout << v[i][j]%MOD<<" ";
        cout << endl;
    }

}
