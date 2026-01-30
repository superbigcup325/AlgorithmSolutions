#include<bits/stdc++.h>
using namespace std;
#define int long long

bool decode(string s, unordered_map<char,int> map) {
    int left = 0;
    int right = 0;
    bool on_left = true;
    int num = 0;
    char sign = '+';
    for (int i = 0; i <= s.length(); i++) {
        char ch = (i < s.length()) ? s[i] : '#';
        //'#'为最后处理num预留
        if (ch == '+' || ch == '-' || ch == '=' || ch == '#') {
            if (num > 0) {
                if (on_left) {
                    if (sign == '+') left += num;
                    else left -= num;
                } else {
                    if (sign == '+') right += num;
                    else right -= num;
                }
                num = 0;
            }
            if (ch == '=') {
                on_left = false;
                sign = '+';
            } else if (ch == '+' || ch == '-') {
                sign = ch;
            }
            continue;
        }
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
            continue;
        }
        auto it = map.find(ch);
        if (it != map.end()) {
            if (on_left) {
                if (sign == '+') left += it->second;
                else left -= it->second;
            } else {
                if (sign == '+') right += it->second;
                else right -= it->second;
            }
        }
    }
    return left == right;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char, int> map;
        while (n--) {
            char var, temp;
            int val;
            cin >> var >> temp >> val;
            map[var] = val;
        }
        if (decode(s, map)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}