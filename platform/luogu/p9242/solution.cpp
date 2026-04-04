#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

inline int getBack(int n) {
    return n%10;
}

signed main() {
    int len;
    cin>>len;
    vector<int> dp(10,0);
    int temp,prev;
    cin>>temp;
    dp[getBack(temp)]++;
    prev=temp;
    for (int i=1;i<len;i++) {
        cin>>temp;
        int front=to_string(temp)[0]-'0';
        dp[getBack(temp)]=max(dp[getBack(temp)],dp[front]+1);
    }
    int ans=-1;
    for (auto size:dp) {
        ans=max(ans,size);
    }
    cout<<len-ans<<endl;
    return 0;
}