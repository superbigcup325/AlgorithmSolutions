#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> alive(n);
        vector<int> spike(m);
        for(int i=0;i<n;i++) {
            cin>>alive[i];
        }
        for(int i=0;i<m;i++) {
            cin>>spike[i];
        }
        unordered_set<int> spk;
        for (auto pos:spike) spk.insert(pos);
        string move;
        int offset=0;
        cin>>move;
        for (int i=0;i<k;i++) {
            if (alive.empty()) {
                cout << alive.size() << (i == k-1 ? "\n" : " ");
                continue;
            }
            if (move[i]=='R') offset++;
            else offset--;
            vector<int> die;
            for (auto pos:alive) {
                int now=pos+offset;
                if (spk.count(now)) {
                    die.push_back(pos);
                }
            }
            for (auto pos:die) {
                alive.erase(pos);
            }
            cout << alive.size() << (i == k-1 ? "\n" : " ");
        }
    }
    return 0;
}