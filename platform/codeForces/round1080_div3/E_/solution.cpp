#include<bits/stdc++.h>
using namespace std;
//#define int long long

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        map<int,pair<int,int>> to;
        map<int,int> from
        vector<char> statu(len+1,' ');
        for(int i=1;i<=len;i++) {
            int l,r;
            cin>>l>>r;
            to[i]={l,r};
            from[l]=i;
            from[r]=i;
        }
        vector<int> ans(len+1);
        for (int i=1;i<=len;i++) {
            if (i==1) {
                ans[i]=1;
                continue;
            }
            auto [l,r]=to[i];
            if (l==0&&r==0) {
                ans[i]=ans[from[i]]+1;
            }
            else if ()
        }
    }
    return 0;
}