#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

// 一开始检查左右界的方法没问题，但是没有处理好边界

signed main() {
    fio;
    int t;
    cin>>t;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> robot(n); for (auto& i : robot) cin>>i;
        vector<int> spike(m); for (auto& i : spike) cin>>i;
        vector<bool> dead(n,false);
        sort (spike.begin(), spike.end());
        map<int,vector<int>> death_loc;
        string move;
        cin>>move;
        for (int i=0;i,n;i++) {
            if (spike[0]<robot[i]) {// 将右侧有刺的找最近刺，将rob推入位移[offset]会死亡的序列中
                int left_dist=robot[i]-(*(lower_bound(spike.begin(),spike.end(),robot[i])-1));
                death_loc[-left_dist].push_back(i);
            }
            if (spike[m-1]>robot[i]) {
                int right_dist=*lower_bound(spike.begin(),spike.end(),robot[i])-robot[i];
                death_loc[right_dist].push_back(i);
            }
        }
        int offset=0;
        int alive=n;
        for (auto ch:move) {
            if (ch=='L') offset--;
            else if (ch=='R') offset++;
            for (int i:death_loc[offset]) {
                if (dead[i]) continue;
                else {
                    dead[i]=true;
                    alive--;
                }
            }
            death_loc[offset].clear();
            cout<<alive<<' ';
        }
        cout<<endl;
    }

    return 0;
}