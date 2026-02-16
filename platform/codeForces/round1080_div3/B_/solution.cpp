#include<bits/stdc++.h>
using namespace std;
//#define int long long

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        vector<int> a(len+1);
        for (int i=1;i<=len;i++) {
            cin>>a[i];
        }
        bool flag=true;
        for (int i=1;i<=len;i++) {
            if (a[i]!=i) {
                int j=i;
                while (j>>2!=0) j>>=1;
                while (j<<1<=len-1) {

                }
            }
        }
        if (flag) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}