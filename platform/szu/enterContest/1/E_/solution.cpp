#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int size;
        cin>>size;
        vector<int> a(size+1);
        for (int i=1;i<=size;i++) cin>>a[i];
        if (size==1) {
            cout<<0<<endl;
            break;
        }
        vector<vector<int>> g(size+1);
        for (int i=1;i<=size-1;i++) {
            int u, v;
            cin>>u>>v;
            g[u].push_back(v);
        }

    }
    return 0;
}