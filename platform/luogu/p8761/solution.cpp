#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

signed main() {
    string s;
    cin >> s;
    for (auto& x:s) {
        if (x >= 'a' && x <= 'z') x += 'A' - 'a';
    }
    cout << s;
    return 0;
}