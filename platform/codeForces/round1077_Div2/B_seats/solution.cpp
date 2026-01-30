#include <bits/stdc++.h>
using namespace std;

//根据全0子段的长度增加[len/3]
//时间复杂度O(n)，空间复杂度O(1)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = 0;
        for (char c : s) {
            if (c == '1') ans++;
        }
        for (int i = 0; i < n; ) {
            if (s[i] == '1') {
                i++;
                continue;
            }
            int j = i;
            while (j < n && s[j] == '0') {
                j++;
            }
            int len = j - i;
            bool l = (i > 0 && s[i-1] == '1');
            bool r = (j < n && s[j] == '1');
            if (l && r) {
                if (len >= 2) {
                    ans += (len - 2 + 2) / 3;
                }
            } else if (l || r) {
                if (len >= 1) {
                    ans += (len - 1 + 2) / 3;
                }
            } else {
                ans += (len + 2) / 3;
            }
            i = j;
        }
        cout << ans << "\n";
    }
    return 0;
}