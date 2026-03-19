#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

// 对于所有式子的组合，因为异或的优先级更高，所以在一串异或运算前，
// 会有加减号将他抵消，留下来的只有前缀的异或，而后面式子的运算符的限制有：
// i+1位不能是异或，再后面任选，故乘以2*3^(n-i-1)
// 特别地，当走到了最后时，对答案的贡献只有前缀异或和

const int mod = 1e9+7;
const int N = 1e5+5;

int fast(int base,int k) {
    int result=1;
    base %= mod;
    while (k) {
        if (k&1) result=(result*base)%mod;
        base=(base*base)%mod;
        k>>=1;
    }
    return result%mod;
}

signed main() {
    int len;
    cin>>len;
    int s=0;
    int ans=0;
    for (int i=1;i<=len;i++) {
        int temp;
        cin>>temp;
        s^=temp;
        if (i<len)
        ans+=(s*2*fast(3LL,len-i-1))%mod;
        else ans+=s;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}