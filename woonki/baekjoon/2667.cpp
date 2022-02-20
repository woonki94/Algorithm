#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int map[25][25];
int size[323];
int cnt;
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isInside(int a, int b){
    return (a>=0 && a<n) && (b>=0 && b<n);
}

void bfs(int a, int b, int mark){

    queue<pair<int, int> > q;
    q.push(pair<int, int>(a, b));
    map[a][b] = mark;

    while(!q.empty()){
        pair<int, int> p;
        int y = p.first = q.front().first;
        int x = p.second = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            if(isInside(y + d[i][0], x + d[i][1]) && map[y + d[i][0]][x + d[i][1]] == 1){
                bfs(y + d[i][0], x + d[i][1], mark);
            }

        }
    }

}

void solution(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n ;j++){
            if(map[i][j] == 1){
                bfs(i, j, cnt+2);
                cnt++;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] ==0) continue;

            size[map[i][j]-2]++;
        }
    }

}



int main(void){
    //입력

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    solution(n);
    sort(size, size+cnt);

    cout << cnt << "\n";
    for(int i=0; i<cnt; i++) {
        cout << size[i] << "\n";
    }

}



