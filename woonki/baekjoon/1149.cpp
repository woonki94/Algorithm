//
// Created by 김운기 on 2022/01/11.
//

//인접한 집과는 같은 색이면 안됨



#include <iostream>

using namespace std;


int min(int x, int y){
    if(x<=y) return x;
    else return y;
}
int min(int x,int y,int z){
    int tmp=0;
    if(x<=y) tmp = x;
    else tmp = y;
    if(tmp<z) return tmp;
    else return z;
}

int main(){

    int n,r,g,b;
    int answer = 0;

    int rgb[1001][3];

    cin >> n;
    cin >> rgb[0][0] >> rgb[0][1] >> rgb [0][2];

    for(int i=1; i<n; i++){
        cin >>r >> g>> b;
        rgb[i][0] = min(rgb[i-1][1]+r,rgb[i-1][2]+r);
        rgb[i][1] = min(rgb[i-1][0]+g, rgb[i-1][2]+g);
        rgb[i][2] = min(rgb[i-1][0]+b, rgb[i-1][1]+b);
    }

    answer = min(rgb[n-1][0],rgb[n-1][1],rgb[n-1][2]);

    cout << answer;



}


