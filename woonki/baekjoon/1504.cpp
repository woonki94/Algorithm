#include<iostream>
#include<vector>
#include<queue>

using namespace std;


vector<pair<int,int>> graph[801];
int d[801];
int v1, v2;


void dijkstra(int start){
    priority_queue<pair<int,int>> pq;

    pq.push({0,start});
    d[start]=0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;

        pq.pop();
        if(d[now]<dist) continue;
        for(int i=0; i< graph[now].size(); i++){
            int cost = dist+graph[now][i].second;
            if(cost<d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main(){
    int N,E;
    cin >> N >> E;

    for(int i =0;i<E; i++){
        int a,b,c;
        cin >>a >> b>> c;
        graph[a].push_back({b,c});
        graph[a].push_back({a,c});
    }
    cin >> v1 >>v2;
    int answer1 = 0;
    int answer2 =0;
    fill(d,d+801,1e9);

    dijkstra(1);
    int a1 = d[v1];
    int a2 = d[v2];

    fill(d,d+801,1e9);

    dijkstra(v1);
    int b1 = d[v2];
    int c2 = d[N];

    fill(d,d+801,1e9);


    dijkstra(v2);
    int c1 = d[N];
    int b2 = d[v1];

    if((a1 == 1e9 || b1 == 1e9 || c1 == 1e9) && (a1 == 1e9 || b1 == 1e9 || c1 == 1e9)){
        cout << -1;
        return 0;
    }

    if(a1+b1+c1> a2+b2+c2){
        cout << a2+b2+c2;
    }
    else
        cout<< a1+b1+c1;



}

