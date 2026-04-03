#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

// 要求O(n)
// 贪心，分配每个时间让减少的最多

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m,l;
        cin>>n>>m>>l;
        int res=0;
        int k
        for (int i=0;i<n;i++) {
            cin>>k;
            res+=k;
            res=res-k<0? 0:res-k;
        }
        res+=l-k+1;
    }
    return 0;
}