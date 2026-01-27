#include<bits/stdc++.h>
using namespace std;
const int MAX = 0x3f3f3f3f;

vector<int> dijkstra(int start,vector<vector<pair<int,int>>>& graph){
    int len=graph.size();
    vector<int> dis(len+1,MAX);
    dis[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
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

int main() {
    cin.tie(nullptr);
	ios::sync_with_stdio(false);
    int v,e,s;
    cin>>v>>e>>s;
    vector<vector<pair<int,int>>> graph(v+1);
    for (int i=0;i<e;i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        graph[from].emplace_back(to,weight);
    }
    vector<int> dis=dijkstra(s,graph);
    for (int i=1;i<=v;i++) cout<<dis[i]<<' ';
    return 0;
}