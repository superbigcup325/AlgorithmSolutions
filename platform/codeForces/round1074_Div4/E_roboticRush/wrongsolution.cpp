#include<bits/stdc++.h>
using namespace std;

//做了些不必要的优化

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        unordered_set<int> robot;
        int temp;
        for (int i=1;i<=n;i++) {
            cin>>temp;
            robot.insert(temp);
        }
        unordered_set<int> spike;
        for (int i=1;i<=m;i++) {
            cin>>temp;
            spike.insert(temp);
        }
        string move;
        int offset=0;
        unordered_map<int,int> firstOffsetTime;
        cin>>move;
        for (int i=0;i<k;i++) {
            if (move[i]=='R') offset++;
            else offset--;
            if (!firstOffsetTime.count(offset)) {
                firstOffsetTime.insert({offset,i});
            }
        }
        vector<int> dead_time(n,k+1);
        for (auto spk:spike) {
            for (auto& [delta,time]:firstOffsetTime) {
                int pos=spk-delta;
                if (robot.count(pos)) {
                    dead_time[pos]=min(dead_time[pos],time);
                }
            }
        }
        vector<int> dead(k,0);
        for (auto time:dead_time) {
            dead[time]++;
        }
        int res=n;
        for (int i=0;i<k;i++) {
            res-=dead[i];
            cout<<res;
            cout<<(i==k-1? '\n':' ');
        }
    }
    return 0;
}