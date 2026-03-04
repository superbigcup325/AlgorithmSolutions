#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

bool isPrime(int n) {
    if (n==1) return false;
    if (n<=3) return true;
    for (int i=2;i*i<=n;i++) {
        if (n%i==0) return false;
    }
    return true;
}

pair<bool,pair<int,int>> one(int n) {
    int base1=1,base2=1;
    for (int i=2;i*i<=n;i++) {
        if (n%i==0) {
            base1=i;
            break;
        }
    }
    while (n%base1==0) {
        n/=base1;
    }
    if (n!=1) for (int i=2;i*i<=n;i++) {
        if (n%i==0) {
            base2=i;
            break;
        }
    }
    while (n%base2==0) {
        n/=base2;
    }
    bool result=n==1;
    return {result,{base1,base2}};
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int len;
        cin >> len;
        vector<int> v(len);
        bool flag = false;
        for (int i = 0; i < len; i++) {
            cin >> v[i];
            if (i) {
                if (v[i]<v[i-1]) {
                    flag=true;
                }
            }
        }
        if (!flag) {
            cout<<"Bob"<<endl;
        }
        int prev=-1;
        for (int i = 0; i < len; i++) {
            if (isPrime(v[i])) {
                if (v[i]<prev) {
                    cout<<"Alice"<<endl;
                    break;
                }
                prev=v[i];
                continue;
            }
            auto [ac,bases]=one(v[i]);
            int base1=bases.first;
            int base2=bases.second;
            if (ac&&base1!=1&&base2!=1) {
                cout<<"Alice"<<endl;
                break;
            }
            else if (ac&&base2==1) {
                if (base1<prev) {
                    cout<<"Alice"<<endl;
                    break;
                }
                prev=base1;
            }
            else if (!ac) {
                cout<<"Alice"<<endl;
                break;
            }
        }
        cout<<"Bob"<<endl;
    }
    return 0;
}