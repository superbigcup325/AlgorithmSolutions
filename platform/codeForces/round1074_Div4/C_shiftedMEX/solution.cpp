#include<bits/stdc++.h>
using namespace std;

// 想求不在序列中的最小非负整数的最大值，则前面必有连续自然数序列
// 本质上是求最长连续子序列的长度

int main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        vector<int> v(len);
        for (int i=0;i<len;i++) {
            cin>>v[i];
        }

        sort(v.begin(),v.end());
        int prev=v[0];
        int ans=0;
        int now=1;
        for (int i=1;i<len;i++) {
            if (v[i]==prev+1) {
                prev=v[i];
                now++;
            }
            else if (v[i]==prev) {
                continue;
            }
            else {
                ans=ans>now? ans:now;
                now=1;
                prev=v[i];
            }
        }
        ans=ans>now? ans:now;
        cout<<ans<<endl;
    }
    return 0;
}