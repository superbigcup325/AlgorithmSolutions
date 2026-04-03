#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int N = 1e5+5;

signed main() {
    int n;
    cin >> n;
    int max=0;
    int ans=1;
    int c=1;
    int size=1;
    while (n>0) {
        int sum=0;
        for (int i=1;i<=size;i++) {
            int temp;
            if (cin >> temp) {
                sum+=temp;
            }
            else break;
        }
        if (sum>max) {
            max=sum;
            ans=c;
        }
        c++;
        size<<=1;
        n>>=1;
    }
    cout << ans << endl;
    return 0;
}