#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

// 对所有的火箭进行暴力深搜

const int mod = 1e9+7;
const int N = 1e5+5;

typedef struct {
    int x,y,r;
}dot;

int dfs(dot d,map<pair<int,int>,vector<int>> &mp,map<pair<int,int>,bool> &vis) {
    int result=0;
    auto [x,y,r]=d;
    for (int i=x-r;i<=x+r;i++) {
        for (int j=y-r;j<=y+r;j++) {
            if ((i-x)*(i-x)+(j-y)*(j-y)>r*r) continue;
            auto k=make_pair(i,j);
            if (mp.count(k)&&!vis[k]) {
                vis[k]=true;
                result+=mp[k].size();
                int maxR=-1;
                for (auto R:mp[k]) maxR=max(maxR,R);
                dot t={k.first,k.second,maxR};
                result+=dfs(t,mp,vis);
            }
        }
    }
    return result;
}

signed main() {
    int n,m;
    cin>>n>>m;
    map<pair<int,int>,vector<int>> mp;
    map<pair<int,int>,bool> vis;
    for (int i=0;i<n;i++) {
        int x,y,r;
        cin>>x>>y>>r;
        mp[{x,y}].push_back(r);
        vis[{x,y}]=false;
    }
    int ans=0;
    for (int i=0;i<m;i++) {
        dot temp;
        cin>>temp.x>>temp.y>>temp.r;
        ans+=dfs(temp,mp,vis);
    }
    cout<<ans;
    return 0;
}