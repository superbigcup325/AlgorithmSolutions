#include <bits/stdc++.h>
using namespace std;

//O((V+E)logV)
//no weight less than 0

vector<int> dijkstra(int start,vector<vector<pair<int,int>>>& graph){
    //graph[from]={to, weight}
    int len=graph.size();
    vector<int> dis(len,INT_MAX);
    dis[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //(weight, dot) sorted by weight
    pq.emplace(0,start);
    while (!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();
        if (d>dis[u]) continue;
        for (auto [v,w]:graph[u]) {
            int newdis=d+w;
            if (newdis<dis[v]){
                dis[v]=newdis;
                pq.emplace(newdis,v);
            }
        }
    }
    return dis;
}

int main () {
    int v,e,start;
    cin >> v >> e >> start;
    vector<vector<pair<int,int>>> graph(v+1);
    for (int i=0;i<e;i++) {
        int from,to,weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to,weight});
    }
    vector<int> dis=dijkstra(start,graph);
    for (int i=1;i<=v;i++) cout << dis[i] << ' ';
    return 0;
}