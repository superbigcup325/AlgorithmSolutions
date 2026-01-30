#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,m;
    cin>>n>>m;
    int sum = 0;
    int num = 0;
    for (int i=1;i<=n;i++) {
        int c,r;
        cin>>c>>r;
        sum += c * r;
        num += 2;
        if (sum>=m) break;
    }
    cout<<num;
    return 0;
}