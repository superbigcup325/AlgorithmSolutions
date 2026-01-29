#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x <= 1) return false;
    if (x<=3) return true;
    for (int i=2;i*i<=x;i++) {
        if (x%i==0) return false;
    }
    return true;
}

int solve(int d) {
    int prev=1;
    int len=1;
    for (int i=1;len<4;i++) {
        if (i>=d+prev&&isPrime(i)) {
            len++;
            if (len==3) {
                return i*prev;
            }
            else prev=i;
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int d;
        cin>>d;
        int ans=solve(d);
        cout<<ans<<endl;
    }
    return 0;
}