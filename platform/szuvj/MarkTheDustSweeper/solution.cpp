#include <bits/stdc++.h>
using namespace std;
#define int long long

int cost(vector<int> &v) {
    int cost = 0;
    int len = v.size();
    int flag=0;
    for (int i = 0; i < len - 1; i++) {
        if (flag==0&&v[i]>0) flag=1;
        if (flag==1) {
            cost+=v[i]==0? 1:v[i];
        }
    }
    return cost;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int len;
        cin >> len;
        vector<int> v(len);
        for (int i = 0; i < len; i++) cin >> v[i];
        cout << cost(v) << endl;
    }
    return 0;
}