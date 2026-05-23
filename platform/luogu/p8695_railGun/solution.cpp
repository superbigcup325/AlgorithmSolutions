#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

// n < 1e3, 可考虑O(n^3)
// 直接遍历每个点 (O(n))， 取余下的点计算相遇时间 (O(n))
// 构建 map[t]=cnt，直接遍历取最大值

signed main() {
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> v(n);
    vector<char> vec(n);
    for (int i=0;i<n;i++) {
        cin>>x[i]>>y[i]>>v[i]>>vec[i];
    }
    int ans=-1;

    // x
    for (int i=0;i<n;i++) {
        int diri=1;
        if (vec[i]=='R') {}
        else if (vec[i]=='L') diri=-1;
        else diri=0;
        int speed_i=v[i]*diri;
        int always_together=0;
        unordered_map<long long,int> mp;

        for (int j=0;j<n;j++) {
            if (i==j) continue;
            int dirj=1;
            if (vec[j]=='R') {}
            else if (vec[j]=='L') dirj=-1;
            else dirj=0;
            int speed_j=v[j]*dirj;

            if (speed_i==speed_j&&x[i]==x[j]) {
                always_together++;
                continue;
            }
            else if (speed_i==speed_j) continue;

            int dx=x[i]-x[j];
            int dv=speed_j-speed_i;
            if (dv==0) continue;
            if (dx%dv!=0) continue;
            long long t=dx/dv;
            if (t<0) continue; 

            mp[t]++;
        }

        ans=max(ans,always_together+1);
        for (auto& [t,cnt]:mp) {
            ans=max(ans,cnt+always_together+1);
        }
    }

    // y
    for (int i=0;i<n;i++) {
        int diri=1;
        if (vec[i]=='U') {}
        else if (vec[i]=='D') diri=-1;
        else diri=0;
        int speed_i=v[i]*diri;
        int always_together=0;
        unordered_map<long long,int> mp;

        for (int j=0;j<n;j++) {
            if (i==j) continue;
            int dirj=1;
            if (vec[j]=='U') {}
            else if (vec[j]=='D') dirj=-1;
            else dirj=0;
            int speed_j=v[j]*dirj;

            if (speed_i==speed_j&&y[i]==y[j]) {
                always_together++;
                continue;
            }
            else if (speed_i==speed_j) continue;

            int dy=y[i]-y[j];
            int dv=speed_j-speed_i;
            if (dv==0) continue;
            if (dy%dv!=0) continue;
            long long t=dy/dv;
            if (t<0) continue; 

            mp[t]++;
        }

        ans=max(ans,always_together+1);
        for (auto& [t,cnt]:mp) {
            ans=max(ans,cnt+always_together+1);
        }
    }

    cout<<ans;
    return 0;
}