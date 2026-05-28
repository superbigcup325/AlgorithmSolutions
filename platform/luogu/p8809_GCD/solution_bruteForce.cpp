#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

// 标记可行部分，遍历左端点，向右扫描
// tle，70pts

signed main() {
    int n,g;
    cin>>n>>g;
    vector<int> vec;
    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        if (__gcd(g,x)==g) vec.push_back(0);
        else vec.push_back(1);
    }

    long long ans=0;
    for (int i=0;i<n;i++) {
        int cnt=0;
        int j=0;
        while (i+j<n&&cnt+(vec[i+j]==1)<=1) {
            cnt+=(vec[i+j]==1);
            j++;
        }
        if (j>1) ans+=j-1;
    }
    
    cout<<ans;
    return 0;
}