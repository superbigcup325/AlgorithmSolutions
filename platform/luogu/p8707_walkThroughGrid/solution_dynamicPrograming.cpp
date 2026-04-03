#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int N = 1e5+5;

signed main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>(m+1,0));
    v[1][1]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if (!(i&1|j&1)) continue;
            if (i>=2) {
                v[i][j]+=v[i-1][j];
            }
            if (j>=2) {
                v[i][j]+=v[i][j-1];
            }
        }
    }
    cout<<v[n][m]<<endl;
    return 0;
}