#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

signed main() {
    int n,m;
    cin>>n>>m;
    vector<char> a(n);
    vector<char> b(m);
    for (auto& x:a) cin>>x;
    for (auto& x:b) cin>>x;
    sort(b.begin(),b.end());
    int i=0,j=0;
    while (i<n&&j<m) {
        if (a[i]<=b[j]) {
            cout<<a[i];
            i++;
        }
        else {
            cout<<b[j];
            j++;
        }
    }
    while (i<n) cout<<a[i++];
    while (j<m) cout<<b[j++];
    return 0;
}