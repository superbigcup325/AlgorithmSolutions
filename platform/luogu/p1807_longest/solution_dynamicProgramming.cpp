#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
const int NEG_INF=-1e18;

const int mod = 1e9+7;
const int N = 1e5+5;

// 根据入度计算拓扑序，根据拓扑序进行dp

signed main() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> edge(n+1);
    vector<int> cnt(n+1,0);
    for(int i=1;i<=m;i++) {
        int from,to,weight;
        cin>>from>>to>>weight;
        edge[from].emplace_back(to,weight);
        cnt[to]++;
    }
    vector<int> dis(n+1,NEG_INF);
    dis[1]=0;
    queue<int> q;
    for (int i=1;i<=n;i++) {
        if (cnt[i]==0) q.push(i);
    }
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        for (auto [v,w] : edge[u]) {
            if (dis[u]!=NEG_INF) {
                dis[v]=max(dis[v],dis[u]+w);
            }
            // 只有u可达才更新
            cnt[v]--; // 计算入度
            if (cnt[v]==0) q.push(v);
        }
    }
    cout<<(dis[n]==NEG_INF? -1: dis[n])<<endl;
    return 0;
}