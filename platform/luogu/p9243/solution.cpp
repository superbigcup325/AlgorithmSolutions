#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

int m,n;

void search(vector<vector<int>>& graph,map<int,vector<pair<int,int>>>& circles, vector<vector<int>>& Id,int x,int y) {
    for (int i=0;i<4;i++) {
        int nx=x+dx[i],ny=y+dy[i];
        if (nx<0||nx>=m||ny<0||ny>=n) continue;
        Id[nx][ny]=Id[x][y];
        circles[Id[x][y]].push_back({nx,ny});
        search(graph,circles,Id,nx,ny);
    }
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>m>>n;
        vector<vector<int>> graph(m,vector<int>(n));
        for (int i=0;i<m;i++) {
           for (int j=0;j<n;j++) {
               cin>>graph[i][j];
           }
        }
        int id=1;
        vector<vector<int>> Id(m,vector<int>(n,0));
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        map<int,vector<pair<int,int>>> circles;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (Id[i][j]) continue;
                else {
                    Id[i][j]=id;
                    circles[Id[i][j]].push_back({i,j});
                    search(graph,circles,Id,i,j);
                    id++;
                }
            }
        }
    }
    return 0;
}