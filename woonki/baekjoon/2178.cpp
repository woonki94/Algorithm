#include <iostream>
#include <queue>


using namespace std;

int n, m;
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int board[102][102];
bool visited[102][102];

void bfs(){
    queue<pair<pair<int, int>, int>> myQueue;
    myQueue.push({{1, 1}, 1});
    visited[1][1] = true;

    while (!myQueue.empty()){
        auto t = myQueue.front();
        myQueue.pop();

        auto tPos = t.first;
        int tx = tPos.first; int ty = tPos.second;
        int cnt = t.second;

        if(tx == n&& ty == m){
            cout << cnt << "\n";
            break;
        }

        for(int i = 0; i < 4; ++i){
            int dx = tx + d[i][0];
            int dy = ty + d[i][1];

            if(dx <= 0 || dy <= 0 || dx > n || dy > m) continue;
            if(visited[dx][dy]) continue;
            if(board[dx][dy] == 0) continue;

            myQueue.push({{dx, dy}, cnt + 1});
            visited[dx][dy] = true;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf("%1d", &board[i][j]);
        }
    }
    bfs();
}
