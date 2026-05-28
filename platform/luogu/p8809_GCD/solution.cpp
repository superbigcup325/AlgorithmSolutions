#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

// 标记可行部分，遍历左端点，向右扫描
// 较暴力做了记忆化右边指针处理，双指针做法

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
    int cnt=0;
    for (int l=0,r=0;l<n;l++) {
        // 扫描直到不能组成新的子数组
        while (r<n&&cnt+(vec[r]==1)<=1) {
            cnt+=(vec[r]==1);
            r++;
        }
        // 结算
        if (r-l>1) ans+=r-l-1;
        cnt-=(vec[l]==1);
    }
    
    cout<<ans;
    return 0;
}