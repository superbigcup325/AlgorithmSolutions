#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m,h;
        cin>>n>>m>>h;
        vector<int> num(n+1);
        vector<int> ans(n+1);
        for (int i=1;i<=n;i++) {
            cin>>num[i];
            ans[i]=num[i];
        }

        while(m--) {
            int b,c;
            cin>>b>>c;
            if (num[b]+c>h) {
                ans=num;//不經濟的重置方法
                continue;
            }
            ans[b]+=c;
        }

        for (int i=1;i<=n;i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}