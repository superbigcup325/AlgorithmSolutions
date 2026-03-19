#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

int a[N];
int l;

void add() {
    int b[N];
    memset(b,0,sizeof(b));
    for (int i=0;i<l;i++) {
        b[i]+=a[i]+a[i];
        if (b[i]>9) {
            b[i+1]+=b[i]/10;
            b[i]%=10;
        }
    }
    while (b[l]) l++;
    for (int i=0;i<l;i++) {
        a[i]=b[i];
    }
}

signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len=s.length();
    int ge=0;
    for (int i=len-1,idx=0;i>=0;i--) {
        char c=s[i];
        if (c=='.') {
            ge=idx;
        }
        else {
            a[idx]=c-'0';
            idx++;
        }
    }
    l=s.length()-1;
    while (n--) add();
    if (a[ge-1]>=5) a[ge]++;
    for (int i=l-1;i>=ge;i--) {
        cout<<a[i];
    }
    return 0;
}