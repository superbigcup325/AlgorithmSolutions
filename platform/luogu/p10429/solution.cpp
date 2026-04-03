#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

// todo

signed main() {
    fio;
    int len;
    cin>>len;
    vector<int> a(len);
    int right=0;
    for(int i=0;i<len;i++) {
        cin>>a[i];
        right+=a[i];
    }
    int left=0;
    int ans=LONG_LONG_MAX;
    for (int i=0;i<len;i++) {
        for (int j=i+1;j<len;j++) {
            int l=i,r=j;

        }
    }
    cout<<ans<<endl;
    return 0;
}