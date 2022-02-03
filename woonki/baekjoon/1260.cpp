#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int visited[10001]; // 해당 노드에 방문 여부 체크
vector<int> D;
vector<int> B;
vector<int> map[10001];  // 연결 노드 저장



void DFS(int v){
    visited[v]=1;
    D.push_back(v);

    for(int i=0 ;i<map[v].size();i++){
        int visit = map[v][i];
        if(visited[visit]==0) {     // 가지 않은 노드일 경우
            DFS(visit);
        }
    }
}

void BFS(int v){
    queue<int> q;
    visited[v]=1;
    q.push(v);

    while(!q.empty()){
        int front=q.front();
        q.pop();
        B.push_back(front);

        for(int i=0;i<map[front].size();i++){
            int visit= map[front][i];

            if(visited[visit]==0){     // 가지 않은 노드일 경우
                q.push(visit);
                visited[visit]=1;
            }
        }
    }
}


int main(){
    int n, m, v;    // 정점 개수, 간선 개수, 탐색 시작 정점
    cin >> n >> m >> v;

    for (int i=0;i<m;i++){  // M 줄 간선
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        sort(map[i].begin(), map[i].end());
    }


    //DFS
    for(int i=0;i<=n;i++) visited[i]=0; // visited 0으로 초기화
    DFS(v);
    for(int i=0; i<D.size(); i++){
        cout << D[i] << "";
    }

    cout << "\n";

    //BFS
    for(int i=0;i<=n;i++)
        visited[i]=0; // DFS로 다녀간 visited 0으로 초기화

    BFS(v);
    for(int i=0; i<B.size(); i++){
        cout << B[i] << "";
    }

}

