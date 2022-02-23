#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321


int Dist[2001];
vector<pair<int, int>> edge[300001];
int v, e, start_node;

void dijkstra(int start) {
    Dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int current = pq.top().second;
        int current_cost = -pq.top().first;
        pq.pop();


        if(Dist[current] < current_cost)
            continue;

        for(int i = 0 ; i < edge[current].size() ; i++) {
            int next = edge[current][i].first;

            int next_cost = current_cost + edge[current][i].second;

            if(Dist[next] > next_cost) {
                Dist[next] = next_cost;
                pq.push({-Dist[next], next});
            }
        }
    }
}

int main() {
    cin >> v >> e >> start_node;

    for(int i = 1 ; i <= v ; i++)
        Dist[i] = INF;

    for(int i = 0 ; i < e ; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;

        edge[start].push_back({end, cost});
    }

    dijkstra(start_node);

    for(int i = 1 ; i <= v ; i++) {
        if(Dist[i] == INF)
            cout << "INF" << "\n";
        else
            cout << Dist[i] << "\n";
    }

}
