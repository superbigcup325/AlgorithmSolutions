#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

// 线性dp，但是常数过大需要用到矩阵快速幂

// todo

signed main() {
    const int mod=1e9+7;
    int n,m;
    int op[]={0,4,5,6,1,2,3};
    cin>>n>>m;
    int mp[7][7]={0};
    for (int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        mp[a][b]=1;
        mp[b][a]=1;
    }
    vector<vector<int>> dp(n,vector<int>(7,0));
    for (int i=1;i<=6;i++) dp[0][i]=4;
    for (int i=1;i<n;i++) {
        for (int j=1;j<=6;j++) {
            for (int k=1;k<=6;k++) {
                if (mp[k][op[j]]) continue;
                dp[i][j]+=dp[i-1][k]*4;
                dp[i][j]%=mod;
            }
        }
    }
    int ans=0;
    for (auto num:dp[n-1]) ans+=num,ans%=mod;
    cout<<ans<<endl;
    return 0;
}