#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

signed main() {
    int len;
    cin>>len;
    vector<int> arr(len);
    vector<int> f(len);
    for (auto& x:arr) cin>>x;
    f[0]=1,f[1]=1;
    for (int i=2;i<len;i++) {
        f[i]=f[i-1]+f[i-2];
    }
    map<int,int> mp;
    for (int i=0;i<len;i++) {
        if (arr[i]%f[i]==0) mp[arr[i]/f[i]]++;
    }
    int maxcnt=-1;
    for (auto& [k,cnt]:mp) {
        maxcnt=max(maxcnt,cnt);
    }
    cout<<len-maxcnt;
    return 0;
}