#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 3e9+10;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,m,k;
        cin >> n >> m >> k;
        unordered_set<int> robot(n);
        vector<int> spike(m);
        for (int i=0;i<n;i++) {
            int temp;
            cin >> temp;
            robot.insert(temp);
        }
        for (int i=0;i<m;i++) {
            cin >> spike[i];
        }
        sort(spike.begin(), spike.end());
        unordered_map<int,pair<int,int>> danger;
        for (int rob : robot) {
            // 使用 upper_bound 避免機器人初始就在尖刺上（題目保證不會）
            auto it = upper_bound(spike.begin(), spike.end(), rob);

            int right_spike = INF;
            if (it != spike.end()) {
                right_spike = *it;
            }

            int left_spike = -INF;
            if (it != spike.begin()) {
                left_spike = *(it - 1);
            }

            danger[rob] = {left_spike, right_spike};
        }
        string move;
        int offset=0;
        cin >> move;
        for (int i=0;i<move.size();i++) {
            if (move[i]=='R') offset++;
            else offset--;
            vector<int> die;
            for (auto rob:robot) {
                int pos=rob+offset;
                auto [l,r]= danger[rob];
                if (pos==l||pos==r) {
                    die.emplace_back(rob);
                }
            }
            for (auto dead:die) {
                robot.erase(dead);
            }
            cout<<robot.size()<<(i==move.size()-1?"\n":" ");
        }
    }
    return 0;
}