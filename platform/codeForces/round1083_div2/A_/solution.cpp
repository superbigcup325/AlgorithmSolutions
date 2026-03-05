#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

signed main() {
    int t;
    cin>>t;
    while (t--) {
        int len;
        cin>>len;
        vector<int> s(len);
        for (auto& i : s) {
            cin>>i;
            if (i==len) swap(s[0],i);
        }
        for (int i = 0; i < len; i++) {
            cout<<s[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}