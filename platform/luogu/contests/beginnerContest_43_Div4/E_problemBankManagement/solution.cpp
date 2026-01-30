#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<set<int>> vec(n);
    vector<int> pos(m+1, 0);
    for (int i=1;i<=m;i++) {
        vec[0].insert(i);
    }
    while (k--) {
        int op,u,v;
        cin>>op>>u>>v;
        if (op==1) {
            int current = pos[u];
            if (current != v) {
                vec[current].erase(u);
                vec[v].insert(u);
                pos[u] = v;
            }
        }
        else if (op==2) {
            if (vec[v].size() < u) {
                cout << -1 << endl;
            }
            else {
                auto it = vec[v].begin();
                advance(it, u-1);
                cout << *it << endl;
            }
        }
    }
    return 0;
}