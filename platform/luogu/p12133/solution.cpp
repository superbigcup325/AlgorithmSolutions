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
        int a,b,c,k;
        cin>>a>>b>>c>>k;
        for (int i=0;i<k;i++) {
            if (a==b&&b==c) break;
            int na,nb,nc;
            na=(b+c)/2;
            nb=(a+c)/2;
            nc=(a+b)/2;
            a=na,b=nb,c=nc;
        }
        cout<<a<<' '<<b<<' '<<c<<endl;
    }
    return 0;
}