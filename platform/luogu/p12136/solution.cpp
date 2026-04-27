#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

void dfs(vector<int>& weight,vector<vector<int>>& adj,vector<vector<bool>>& pack,int begin,int p) {
    pack[begin][0]=true;
    if (adj[begin].size()==1&&begin!=1) { // 叶子节点
        pack[begin][weight[begin]]=true;
        return;
    }

    for (const auto& to:adj[begin]) {
        if (to==p) continue;
        dfs(weight,adj,pack,to,begin);
        vector<bool> old=pack[begin];
        for (int j=0;j<=weight[begin];j++) {
            // 枚举目标容量 因为大容量由小容量积累，所以从0开始
            if (!old[j]) {continue;}
            for (int k=0;j+k<=weight[begin];k++) { // 枚举子节点能做到的容量
                if (pack[to][k]) {
                    pack[begin][j+k]=true;
                }
            }
        }
    }
}

signed main() {
    int n;
    cin>>n;
    vector<int> weight(n+1);
    vector<vector<int>> adj(n+1);
    vector<vector<bool>> pack(n+1,vector(1010,false));
    for (int i=1;i<=n;i++) cin>>weight[i];
    for (int i=1;i<=n-1;i++) {
        int from,to;
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    dfs(weight,adj,pack,1,0);
    int ans=0;
    for (int i=weight[1];i>=0;i--) {
        if (pack[1][i]) {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}