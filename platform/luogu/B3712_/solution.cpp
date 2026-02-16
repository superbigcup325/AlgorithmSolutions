#include<bits/stdc++.h>
using namespace std;
//#define int long long

bool chk(vector<unordered_set<int>>& py,vector<unordered_set<int>>& dr,int a,int b) {
    for (auto& apy:py[a]) {
        if (dr[apy].count(b)) {
            return false;
        }
    }
    for (auto& bpy:py[b]) {
        if (dr[bpy].count(a)) {
            return false;
        }
    }
    return true;
}

signed main() {
    int n,p,q;
    vector<unordered_set<int>> py;
    vector<unordered_set<int>> dr;
    cin>>n>>p>>q;
    for (int i = 0; i < p; i++) {//朋友
        int a,b;
        cin>>a>>b;
        py[a].emplace(b);
        py[b].emplace(a);
    }
    for (int i = 0; i < q; i++) {
        int a,b;
        cin>>a>>b;
        dr[a].emplace(b);
        dr[b].emplace(a);
    }
    int ans=n*(n-1)/2;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (py[i].count(j)) {continue;}
            if (dr[i].count(j)) {
                ans--;
            }
            else if (!chk(py,dr,i,j)) {
                ans--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}