#include<bits/stdc++.h>
using namespace std;

// 将指数用二进制表示，把时间复杂度由O(n)优化为O(logn)

const int mod = 1e9 + 7;

long long pow(int num, int k) {
    long long result = 1;
    long long base = num;
    while (k > 0) {
        if (k & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        k >>= 1;
    }
    return result;
}

signed main() {
    int num, k;
    cin >> num >> k;
    cout << pow(num, k) << endl;
    return 0;
}
