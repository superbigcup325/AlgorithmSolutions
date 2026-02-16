#include<bits/stdc++.h>
using namespace std;
//#define int long long

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m,ans=0;
        cin>>n>>m;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++) {
            int temp;
            cin>>temp;
            if (map.count(temp)) {
                map[temp]++;
            }
            else {
                map[temp]=1;
            }
        }
        for (int k=1;k<=m;k++) {
            int t=gcd(n,k);
            int set=n/t;
            bool flag=true;
            for (auto [num,cnt]:map) {
                if (cnt%set!=0) {
                    flag=false;
                    break;
                }
            }
            if (!flag) {continue;}
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}