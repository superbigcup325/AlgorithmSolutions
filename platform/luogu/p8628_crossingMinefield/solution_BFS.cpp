#include <bits/stdc++.h>
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int len;

struct hajimi {
    int x;int y;int statu;int step;
};

bool inside(int x,int y) {
    if (x>=1 && x<=len && y>=1 && y<=len) return true;
    return false;
}

int bfs(int a_x,int a_y,vector<vector<char>>& a,int len) {
    vector<vector<bool>> vis(len+1,vector<bool>(len+1,false));
    queue<hajimi> q;
    q.push({a_x,a_y,0,0});
    while(!q.empty()) {
        hajimi now=q.front();
        q.pop();
        for (int i=0;i<4;i++) {
            int nx=now.x+dx[i];
            int ny=now.y+dy[i];
            if (!inside(nx,ny)) {continue;}
            if (((a[nx][ny]=='+'&&now.statu==-1)||(a[nx][ny]=='-'&&now.statu==1)||now.statu==0)&&!vis[nx][ny]) {
                int statu=a[nx][ny]=='+'? 1:-1;
                vis[nx][ny]=true;
                q.push({nx,ny,statu,now.step+1});
            }
            else if (a[nx][ny]=='B') {
                return now.step+1;
            }
        }

    }
    return -1;
}

int main()
{
    cin>>len;
    vector<vector<char>> a(len+1,vector<char>(len+1));
    int mem_x,mem_y;
    for(int i=1;i<=len;i++)
        for(int j=1;j<=len;j++) {
            cin>>a[i][j];
            if (a[i][j]=='A') mem_x=i,mem_y=j;
        }
    cout<<bfs(mem_x,mem_y,a,len);
    return 0;
}