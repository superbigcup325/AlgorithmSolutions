#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int len,x;
        cin >> len >> x;
        vector<int> a(len);
        int sum = 0;
        int max = 0;
        for (int i = 0; i < len; i++) {
            cin>>a[i];
            sum += a[i];
            max=max>a[i]? max: a[i];
        }
        int ans=(sum+x-1)/x>max? (sum+x-1)/x:max;
        cout<<ans<<"\n";
    }
    return 0;
}