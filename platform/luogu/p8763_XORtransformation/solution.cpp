#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

void transform(string& str) {
    for (int i=str.length()-1;i>0;i--) {
        str[i]=str[i]==str[i-1]? '0':'1';
    }
}

signed main() {
    fio;
    int len,t;
    string s;
    cin>>len>>t>>s;
    string backup=s;
    int T=0;
    for (int i=0;i<t;i++) {
        transform(s);
        if (s==backup) {
            T=i+1;
            break;
        }
        if (i==t-1) {
            cout<<s;
            return 0;
        }
    }
    t%=T;
    for (int i=0;i<t;i++) {
        transform(backup);
    }
    cout<<backup;
    return 0;
}