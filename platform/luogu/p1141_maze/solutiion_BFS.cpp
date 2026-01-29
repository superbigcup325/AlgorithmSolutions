#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int len, t;


int bfs(int x, int y, vector<vector<int>>& graph,vector<vector<int>>& comp,int id) {
    comp[x][y]=id;
    queue<pair<int,int>> q;
    vector<pair<int,int>> cells;
    q.emplace((pair<int,int>){x,y});
    cells.emplace_back((pair<int,int>){x,y});
    while (!q.empty()) {
        auto [px, py] = q.front();
        q.pop();
        int prev=graph[px][py];
        for (int i = 0; i < 4; i++) {
            int nx = px + dx[i];
            int ny = py + dy[i];
            if (nx<1||nx>len||ny<1||ny>len) continue;
            if (comp[nx][ny]!=0) continue;
            if (graph[nx][ny]!=prev) {
                cells.emplace_back((pair<int,int>){nx,ny});
                q.emplace((pair<int,int>){nx,ny});
                comp[nx][ny]=id;
            }
        }
    }
    return cells.size();
}

int main() {
    cin >> len >> t;
    vector<vector<int> > graph(len + 1, vector<int>(len + 1, 0));
    vector<vector<int> > comp(len + 1, vector<int>(len + 1, 0));
    for (int i = 1; i <= len; i++)
        for (int j = 1; j <= len; j++)
            scanf("%1d", &graph[i][j]);

    int id = 0;
    vector<int> size((len + 1) * (len + 1),0);
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            if (comp[i][j]==0) {
                id++;
                size[id]=bfs(i,j,graph,comp,id);
            }
        }
    }

    while (t--) {
        int x, y;
        cin >> x >> y;
        cout << size[comp[x][y]] << endl;;
    }
    return 0;
}