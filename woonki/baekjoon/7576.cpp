#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int tomato[1001][1001];
int date[1001][1001];
queue<pair<int,int>> q;

int row,col;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int result = 0;

void bfsTomato(){ 
    while(!q.empty()){

        int tomatoX = q.front().first;
        int tomatoY = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int tempX = tomatoX + dx[i];
            int tempY = tomatoY + dy[i];
            if(tempX>=0 && tempX<row && tempY>=0 && tempY <col){
                if(tomato[tempX][tempY]==0 && date[tempX][tempY]==-1){
                    date[tempX][tempY] = date[tomatoX][tomatoY] + 1;
                    q.push(make_pair(tempX,tempY));
                }
            }
        }
    }
}

int main(){

    cin>>col>>row;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>tomato[i][j];
            date[i][j] = -1;
            if(tomato[i][j]==1){
                q.push(make_pair(i,j));
                date[i][j]=0;
            }
        }
    }

    bfsTomato();

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(result<date[i][j]){
                result = date[i][j];
            }
        }
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(date[i][j]==-1 && tomato[i][j]!=-1){
                result = -1;
            }
        }
    }
    cout<<result;
}

