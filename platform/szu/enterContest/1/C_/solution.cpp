#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 10;
const int N = 1e5+5;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;

int dfs(vector<vector<char>>& g,map<int,int>& cnt,vector<vector<int>>& id,int x,int y,int Id)  {
    int size=1;
    for (int i=0;i<4;i++) {
        int nx=x+dx[i],ny=y+dy[i];
        if (nx<0||nx>=n||ny<0||ny>=m) continue;
        if (!id[nx][ny]&&g[nx][ny]!='*') {
            id[nx][ny]=Id;
            size+=dfs(g,cnt,id,nx,ny,Id);
        }
    }
    return size;
}

signed main() {
    fio;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> g[i][j];
    map<int,int> cnt;
    vector<vector<int>> id(n,vector<int>(m,0));
    int Id=1;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (!id[i][j]&&g[i][j]!='*') {
                id[i][j]=Id;
                cnt[Id]=dfs(g,cnt,id,i,j,Id);
                Id++;
            }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (g[i][j]=='.') cout<<'.';
            else {
                int ans=1;
                for (int k=0;k<4;k++) {
                    int nx=i+dx[k],ny=j+dy[k];
                    if (nx<0||nx>=n||ny<0||ny>=m) continue;
                    ans+=cnt[id[nx][ny]];
                }
                cout<<ans;
            }
            // cout << cnt[id[i][j]] << " ";
        }
        cout << endl;
    }
    return 0;
}