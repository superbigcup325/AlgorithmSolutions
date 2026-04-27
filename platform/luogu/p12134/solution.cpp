#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

signed main() {
    int n,m;
    cin>>n>>m;
    vector <int> v(n);
    for (auto& x: v) cin>>x;
    sort(v.begin(), v.end());
    deque<int> q;
    vector<int> sum(1,0);
    int ans=LONG_LONG_MAX;
    for (int i=0;i<n-m+1;i++) {
        int next=v[m+i-1]*v[m+i-1]-v[i]*v[i];
        ans=min(ans,next);
    }
    cout<<ans<<endl;
    return 0;
}