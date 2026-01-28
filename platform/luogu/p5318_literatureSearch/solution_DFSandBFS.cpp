#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph,int from) {
    static vector<bool> vis(graph.size() + 1, false);
    vis[from] = true;
    cout<<from<<' ';
    for (auto to: graph[from]) {
        if (!vis[to]) {
            dfs(graph, to);
        }
    }
}

void bfs(vector<vector<int>> &graph, int start) {
    vector<bool> vis(graph.size() + 1, false);
    queue<int> q;
    q.push(start);
    vis[start]=true;
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        cout<<from<<" ";
        for (auto to: graph[from]) {
            if (!vis[to]) {
                vis[to] = true;
                q.push(to);
            }
        }
    }
}

int main () {
    int v,e;
    cin>>v>>e;
    vector<vector<int>> graph (v + 1);
    for (int i = 0; i < e; i++) {
        int from, to;
        cin>>from>>to;
        graph[from].push_back(to);
    }
    for (int i = 1; i < v + 1; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(graph, 1);
    cout<<endl;
    bfs(graph, 1);
    return 0;
}