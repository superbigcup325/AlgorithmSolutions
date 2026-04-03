#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

// 统计最大可为1的串的长度，根据长度增加答案

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        string s;
        cin>>len;
        cin>>s;
        int big=0,small=0;
        int prev=0;
        int cnt=0;
        for (int i=0; i<len; i++) {
            int n=s[i]-'0';
            if (n==1) {
                cnt++;
            }
            else if (n==0&&prev==1&&s[i+1]=='1') {
                cnt++;
            }
            else {
                big+=cnt;
                if (cnt!=0) {
                    if (cnt&1) small+=(cnt+1)/2;
                    else small+=cnt/2+1;
                }
                cnt=0;
            }
            prev=n;
        }
        big+=cnt;
        if (cnt!=0) {
            if (cnt&1) small+=(cnt+1)/2;
            else small+=cnt/2+1;
        }
        cout<<small<<' '<<big<<endl;
    }
    return 0;
}