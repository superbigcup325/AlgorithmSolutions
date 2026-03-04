#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

signed main() {
    string a;
    int t;
    cin>>a>>t;
    map<string,int> mp;
    while (t--) {
        string s;
        cin>>s;
        sort(s.begin(), s.end());
        mp[s]++;
    }
    int ans=0;
    for (int i=0;i<a.size()-7;i++) {
        string x=a.substr(i,8);
        sort(x.begin(), x.end());
        ans+=mp[x];
    }
    cout<<ans<<endl;
    return 0;
}