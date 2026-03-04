#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

// 显然数字最大的是会胜利的，所以我们要找最大数的出现次数
// 下列方法空间开销不理想，建议看示例

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        vector<int> a(len);
        map<int, int> mp;
        for(int i=0;i<len;i++) {
            cin>>a[i];
            if (!mp.count(a[i])) {
                mp[a[i]]=1;
            }
            else {
                mp[a[i]]++;
            }
        }
        int ans=-1;
        int maxnum=-1;
        for (auto [num,times]:mp) {
            if (num>maxnum) {
                maxnum=num;
                ans=times;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}