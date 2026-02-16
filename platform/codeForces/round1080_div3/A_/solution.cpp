#include<bits/stdc++.h>
using namespace std;
//#define int long long

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        bool flag=false;
        for(int i=0;i<len;i++) {
            int temp;
            cin>>temp;
            if(temp==67) {
                flag=true;
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