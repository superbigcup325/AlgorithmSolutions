#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

void dfs(vector<set<int>> &p,vector<int>& dp,int begin) {
    int result=0;
    for (auto dot:p[begin]) {
        result=max(result,dp[dot]);
    }
    dp[begin]=p[begin].size()+result;
}

signed main() {
    int t;
    cin>>t;
    vector<set<int>> p;
    for(int i=2;i<=t;i++) {
        int parent;
        cin>>parent;
        p[parent].insert(i);
    }
    vector<int> dp(t);
    dp[0]=1;
    dfs(p,dp,0);
    cout<<dp[t-1]<<endl;
    return 0;
}