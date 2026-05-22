#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

signed main() {
    int n,l,r;
    cin>>n>>l>>r;
    int mink,maxk;
    long long k;
    k=(long long)sqrt(l);
    while (k*k<l) k++;
    mink=k;
    k=(long long)sqrt(r);
    while (k*k>r) k--;
    maxk=k;
    int ans=r-l+1-max((long long)0,maxk-mink+1);
    cout<<ans;
    return 0;
}