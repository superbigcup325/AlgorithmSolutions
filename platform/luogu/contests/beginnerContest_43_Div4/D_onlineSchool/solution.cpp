#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> c(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int s, t;
            cin >> s >> t;
            c[i].push_back({s, t});
        }
        sort(c[i].begin(), c[i].end());
    }
    int current_day = 0;
    for (int i = 0; i < n; i++) {
        int next_start = current_day + 1;
        auto it = lower_bound(c[i].begin(), c[i].end(),
                             make_pair(next_start, 0));

        if (it == c[i].end()) {
            cout << -1 << endl;
            return 0;
        }

        int min_end = INT_MAX;
        for (auto jt = it; jt != c[i].end(); ++jt) {
            if (jt->second < min_end) {
                min_end = jt->second;
            }
        }
        if (min_end > m) {
            cout << -1 << endl;
            return 0;
        }
        current_day = min_end;
    }

    cout << current_day << endl;
    return 0;
}