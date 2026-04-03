#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

inline int min(int a, int b){return a<b? a:b;}
inline int max(int a, int b){return a>b? a:b;}
// todo
signed main() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    int r=-1,l=INT_MAX;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        cin>>b[i];
        r=max(r,a[i]/b[i]);
        l=min(l,a[i]/b[i]);
    }
    cout<<l<<' '<<r;
    return 0;
}