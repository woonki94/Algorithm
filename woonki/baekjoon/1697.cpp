#include <iostream>
#include <queue>
using namespace std;


int n, k;
int pos[100001];


int BFS(int x)
{
    queue<int> q;
    q.push(x);
    pos[x] = 1;

    while (!pos[k]) {
        int x = q.front();
        int dx[] = { -1, 1, x };
        q.pop();

        for (int i = 0; i < 3; i++) {
            int nx = x + dx[i];

            if (nx < 0 || nx > 100000)
                continue;

            if (pos[nx])
                continue;

            q.push(nx);
            pos[nx] = pos[x] + 1;
        }
    }

    return pos[k] - 1;
}


int main()
{
    cin >> n >> k;

    cout << BFS(n) << '\n';

}

