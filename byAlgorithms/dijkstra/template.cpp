#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int start,vector<vector<pair<int,int>>>& graph){
    //graph[from]={to, weight}
    int len=graph.size();
    vector<int> dis(len+1,INT_MAX);
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