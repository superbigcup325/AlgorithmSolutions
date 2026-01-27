#include <iostream>
#include <queue>
#include <cstring>
#define int long long
using namespace std;

const int N = 500;
int n,m,x,y,t;
int a[N][N];
bool vis[N][N];
int dx[] = {2,2,1,1,-2,-2,-1,-1};
int dy[] = {-1,1,2,-2,1,-1,2,-2};

struct hajimi
{
    int x,y,t;
};


void manbo()
{
    queue<hajimi> q;
    vis[x][y]=true;
    q.push({x,y,0});
    a[x][y]=0;
    while (!q.empty())
    {
        hajimi laoda=q.front();
        q.pop();
        for (int i=0;i<8;i++)
        {
            int nx=laoda.x+dx[i],ny=laoda.y+dy[i];
            if (nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny])
            {
                vis[nx][ny]=true;
                q.push({nx,ny,laoda.t+1});
                a[nx][ny]=laoda.t+1;
            }
        }
    }
}



signed main() {
    cin>>n>>m;
    cin>>x>>y;
    memset(a,-1,sizeof(a));
    manbo();
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            if (vis[i][j]) cout<<a[i][j]<<' ';
            else cout<<-1<<' ';
        cout<<endl;
    }
    return 0;
}