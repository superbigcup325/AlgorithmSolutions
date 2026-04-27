#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

signed main() {
    int len;
    cin>>len;
    int ans=0;
    while (len--) {
        int temp;
        cin>>temp;
        if (temp!=1) ans++;
    }
    cout<<ans<<endl;
    return 0;
}