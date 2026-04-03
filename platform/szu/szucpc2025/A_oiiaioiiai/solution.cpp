#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int len=n;
        vector<int> a(n+1);
        bool right=true,left=false;
        int r=n,l=1;
        while (n>0) {
            if (right) {
                a[r--]=n--;
                if (n==0) break;
                a[l++]=n--;
            }
            else {
                a[l++]=n--;
                if (n==0) break;
                a[r--]=n--;
            }
            right=!right;
            left=!left;
        }
        for (int i=1;i<=len;i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}