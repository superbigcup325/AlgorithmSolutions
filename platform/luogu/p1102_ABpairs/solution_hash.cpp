#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int N = 1e5+5;

signed main() {
    int len,c;
    cin>>len>>c;
    vector<int> v(len);
    map<int,int> mp;
    for (int i=0;i<len;i++) {
        cin>>v[i];
        mp[v[i]]++;
    }
    int ans=0;
    for (int i=0;i<len;i++) {
        ans+=mp[v[i]+c];
    }
    cout<<ans<<endl;
    return 0;
}