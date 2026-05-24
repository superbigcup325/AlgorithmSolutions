#include<iostream>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

// 求的是 a/b 的小数部分的第 n 位到第 n+2 位
// 而小数部分的第n位，其实就是 a/b 经过 n-1 次乘以 10， 即 a/b*10^(n-1) 的个位
// 之后每次乘以 10 就是下一位的个位 （实际上也是一种除法的模拟）
// 注意取模

int qpow(int a,int n,int b) {
    int ans=1;
    int base=a;
    while (n) {
        if (n&1) ans=1LL*ans*base%b;
        base=1LL*base*base%b;
        n>>=1;
    }
    return ans;
}

signed main() {
    int a,b,n;
    cin>>a>>b>>n;
    a%=b;
    int pow=qpow(10,n-1,b);
    a=1LL*a*pow%b;
    for (int i=0;i<3;i++) {
        a*=10;
        cout<<a/b;
        a%=b;
    }
    return 0;
}