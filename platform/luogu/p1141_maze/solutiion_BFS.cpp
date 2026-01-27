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
        pair<int,int> p = q.front();
        q.pop();
        int prev=graph[p.first][p.second];
        for (int i = 0; i < 4; i++) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if (x<1||x>len||y<1||y>len) continue;
            if (comp[x][y]!=0) continue;
            if (graph[x][y]!=prev) {
                cells.emplace_back((pair<int,int>){x,y});
                q.emplace((pair<int,int>){x,y});
                comp[x][y]=id;
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