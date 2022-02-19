#include <iostream>
using namespace std;

int com[101][101]={0};
int visit[101]={0};
int cnt=0;

void dfs(int start,int net)
{
    int i;

    visit[start]=1;
    cnt++;

    for(i=1;i<=net;i++)
    {
        if(com[start][i]==1 && visit[i]==0)
        {
            dfs(i,net);
        }
    }

    return;
}

int main()
{
    int num,net,x,y;
    cin >> num >> net;

    for(int i=0;i<net;i++)
    {
        cin >> x >> y;
        com[x][y]=1;
        com[y][x]=1;
    }

    dfs(1,num);
    cout << cnt-1;

}



