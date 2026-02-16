#include<bits/stdc++.h>
using namespace std;
//#define int long long

bool isOK(int x,int y) {
    if (x==1||x==6) {
        if (y!=6&&y!=1) return true;
    }
    if (x==2||x==5) {
        if (y!=5&&y!=2) return true;
    }
    if (x==3||x==4) {
        if (y!=4&&y!=3) return true;
    }
    return false;
}

signed main() {
    int t;
    cin>>t;
    while (t--) {
        int len;
        cin>>len;
        vector<int> v(len);
        for (int i=0;i<len;i++) {
            cin>>v[i];
        }
        double ans=0;
        for (int i=1;i<len;i++) {
            if (!isOK(v[i],v[i-1])) {
                if (i==1||i==len-1) ans+=1;
                else {

                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}