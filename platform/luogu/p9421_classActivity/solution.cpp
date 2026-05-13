#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

// O(n)
// 需要将冗余的（r）和单身的（s）进行匹配
// 其中r >= s 时，需要进行r+（r-s）次，这里因为r是冗余项，所以需要变为新id
// r < s 时，需要进行r+（r-s）/ 2 次，因为s是单身项，所以直接其中一半变为另一半就好了
// 注意，由于题目数据，上述不需要考虑奇数问题

signed main() {
    fio;
    int n;
    cin>>n;
    unordered_map<int,int> mp;
    while (n--) {
        int tmp;
        cin>>tmp;
        mp[tmp]++;
    }
    long long r=0,s=0;
    for (auto& [num,cnt]:mp) {
        if (cnt==1) s++;
        else if (cnt>=3) r+=cnt-2;
    }
    long long ans=r>s? r:(r+s)/2;
    cout<<ans;
    return 0;
}