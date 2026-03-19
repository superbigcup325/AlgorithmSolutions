#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

// 题目提到对应串分前后，还不能有相交

const int mod = 1e9+7;
const int N = 1e5+5;

signed main() {
    string s;
    cin >> s;
    string t;
    int slen = s.length();
    map<pair<int,string>,vector<int>> mp;
    int ans=0;
    // 做反转串，方便提取
    for (auto x:s) t+=x=='0'? '1':'0';
    // 记录所有子串及其对应信息
    for (int len=1;len<slen;len++) {
        for (int begin=0;begin+len<=slen;begin++) {
            string sub=s.substr(begin,len);
            mp[{len,sub}].push_back(begin);
        }
    }
    // 做反转串，判断是否可行
    for (int len=1;len<slen;len++) {
        for (int begin=0;begin+len<=slen;begin++) {
            string sub=t.substr(begin,len);
            auto k=make_pair(len,sub);
            if (mp.count(k)) {
                for (auto pos:mp[k]) {
                    if (pos>begin+len-1) ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

// 过于暴力 TLE
// for (int len=1;len<=(n+1)/2;len++) {
//     for (int begin=0;begin+len<=n;begin++) {
//         string t1=s.substr(begin,len);
//         for (int next=begin+len;next<=n;next++) {
//             string t2=s.substr(next,len);
//             if (t1==change(t2)) {
//                 ans++;
//             }
//         }
//     }
// }