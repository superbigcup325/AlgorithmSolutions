#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        int n,m,h;
        cin>>n>>m>>h;
        vector<int> num(n+1);
        for (int i=1;i<=n;i++) {
            cin>>num[i];
        }
        vector<pair<int,int>> vec;//記錄每一步操作，溢出時回退
        while (m--) {
            int b,c;
            cin>>b>>c;
            vec.push_back({b,num[b]});
            num[b]+=c;
            if (num[b]>h) {
                while (!vec.empty()) {
                    auto [idx,val]=vec.back();
                    vec.pop_back();
                    num[idx]=val;
                }
            }
        }
        for (int i=1;i<=n;i++) {
            cout<<num[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}