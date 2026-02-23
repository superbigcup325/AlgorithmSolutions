#include<bits/stdc++.h>
using namespace std;
//#define int long long

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        string s;
        cin>>s;
        int b=len/2,a=(len+1)/2;
        // 奇数只能a开头
        if (len&1&&s[0]=='b') {
            cout<<"no"<<endl;
            continue;
        }
        set<char> choose;
        if (len&1) {
            choose={'a'};
        }
        else choose={'a','b'};
        bool flag=true;
        for (int i=0;i<len;i++) {
            char chose;
            if (s[i]=='?') {
                if (choose.size()==1) {
                    for (auto ch:choose) {
                        chose=ch;
                    }
                    choose={'a','b'};
                }
                else {

                }
            }
            else {
                chose=s[i];
                if (choose.count(s[i])) {
                    choose.erase(s[i]);
                    if (choose.empty()) choose={'a','b'};
                }
            }
            if (chose=='a') {
                a--;
            }
            else b--;
            if (a<0||b<0) {
                flag=false;
                break;
            }
        }
        if (flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}