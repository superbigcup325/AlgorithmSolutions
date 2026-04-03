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
        set<int> c;
        set<int> r;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int temp;
                cin>>temp;
                if (temp==1) {
                    c.insert(i);
                    r.insert(j);
                }
            }
        }
        if (c.size()==n||r.size()==n) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}