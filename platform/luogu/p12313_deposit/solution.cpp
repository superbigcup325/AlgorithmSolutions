#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

int delta(int value) {
    int result = value * 5 / 100000;
    return result >= 1? result: 0;
}

int toI(string& s) {
    int intpart = 0;
    int fracpart = 0;
    bool pointed = false;
    int fraclen = 0;
    for (auto& c: s) {
        if (c == '.') pointed =true;
        if (c >= '0' && c <= '9')
        if (!pointed) {
            intpart = intpart * 10 + c - '0';
        }
        else {
            fraclen ++;
            fracpart = fracpart * 10 + c - '0';
            if (fraclen == 2) break;
        }
    }

    while (fraclen < 2) fracpart *= 10, fraclen++;
    return (s[0] == '-'? -1:1) * (intpart * 100 + fracpart); 
}

signed main() {
    int t;
    cin >> t;
    int prev = 0;
    while (t--) {
        prev += delta(prev);
        string op;
        cin >> op;
        int delta = toI(op);
        prev += delta;
        cout << prev / 100 << "." << setw(2) << setfill('0') << (prev % 100) << endl;
    }
    return 0;
}