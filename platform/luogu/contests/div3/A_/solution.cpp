#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,m,k;
    cin>>n>>m>>k;
    if (k>=n) {
        int ans=n*(m-1);
        cout<<ans<<endl;
    }
    else {
        int ans=n*m-k;
        cout<<ans<<endl;
    }
    return 0;
}