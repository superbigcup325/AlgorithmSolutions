#include<bits/stdc++.h>
using namespace std;
//#define int long long

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int x,y;
        cin>>x>>y;
        int ans=0;
        ans+=y;
        if (y>0) {
            x-=y*2;
        }
        else x+=y*4;
        cout<<11-t<<endl;
        cout<<x<<endl;
        if (x%3==0&&x>=0) {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}