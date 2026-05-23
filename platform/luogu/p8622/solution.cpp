#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

// 数据范围：1 < L < R < N < 1e15
// 那么只需要看 [L, R] 的情况
// 对于第 i 个， 他的因数肯定在之前出现过，那么 i 的状态只取决于因数的奇偶性
// 又显然，仅有完全平方数存在奇数个因数
// 那么我们可以将问题转化为统计 [L, R] 区间内的完全平方数个数

signed main() {
    int n,l,r;
    cin>>n>>l>>r;
    int mink,maxk;
    long long k;
    k=(long long)sqrt(l);
    while (k*k<l) k++;
    mink=k;
    k=(long long)sqrt(r);
    while (k*k>r) k--;
    maxk=k;
    int ans=r-l+1-max((long long)0,maxk-mink+1);
    cout<<ans;
    return 0;
}