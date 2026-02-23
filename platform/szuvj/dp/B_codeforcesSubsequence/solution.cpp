#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int k;
    cin>>k;
    string s="codeforces";
    vector<int> v(10,1);
    int product=1;
    int idx=0;
    while (product<k) {
        product = product / v[idx] * (v[idx] + 1);
        v[idx]++;
        idx = (idx + 1) % 10;
    }
    for (int i=0;i<10;i++) {
        for (int j=0;j<v[i];j++) {
            cout<<s[i];
        }
    }
    return 0;
}