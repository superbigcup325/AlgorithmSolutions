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
        string a,b;
        cin>>a>>b;
        map<char,int> mp1;
        map<char,int> mp2;
        for (auto ch:a) mp1[ch]++;
        for (auto ch:b) mp2[ch]++;
        int ans=0;
        for (char i='a';i<='z';i++) {
            ans+=max(mp1[i],mp2[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}