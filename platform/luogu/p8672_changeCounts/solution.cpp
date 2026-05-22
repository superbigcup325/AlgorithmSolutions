#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

// 可以直接枚举6种排列，复杂度可接受
// 对于给定排列方式，由于数目是确定的，所以能够直接得出期望
// 根据期望计算 A -> B 的数量和 B -> A 的数量，可匹配的交换是最优处理
// 余下的因为只有三种类型，可以在两次交换实现到达目标位置

signed main() {
    const string arr[]={
        "ABT", "ATB",
        "BAT", "BTA",
        "TAB", "TBA"
    };
    string str;
    cin>>str;
    map<char,int> mp;
    for (auto c:str) {
        mp[c]++;
    }
    int ans=INT_MAX;
    for (auto& s:arr) {
        char A=s[0];
        char B=s[1];
        char T=s[2];
        map<pair<char,char>,int> cnt;
        for (int i=0;i<str.size();i++) {
            if (i<mp[A]){
                if (str[i]!=A) cnt[{str[i],A}]++;
            }
            else if (i<mp[A]+mp[B]){
                if (str[i]!=B) cnt[{str[i],B}]++;
            }
            else {
                if (str[i]!=T) cnt[{str[i],T}]++;
            }
        }
        int cnt1=min(cnt[{A,B}],cnt[{B,A}]);
        int remain1=max(cnt[{A,B}],cnt[{B,A}])-cnt1;
        int cnt2=min(cnt[{B,T}],cnt[{T,B}]);
        // remain2==remain1
        int cnt3=min(cnt[{A,T}],cnt[{T,A}]);
        // remain3==remain1
        ans=min(cnt1+cnt2+cnt3+remain1*2,ans);
    }
    cout<<ans;
    return 0;
}