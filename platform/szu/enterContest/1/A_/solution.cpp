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
        int num;
        cin>>num;
        int ans=5;
        for (int i=0;i*5<num;i++) {
            ans=ans<(num-(5*i))%3? ans:(num-(5*i))%3;
            if (ans==0) break;
        }
        cout<<ans<<"\n";
    }
    return 0;
}