#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long


const int mod = 1e9+7;
const int N = 1e5+5;

signed main() {
    fio;
    string s1,s2;
    cin>>s1>>s2;
    for (auto &ch:s1) if (ch=='.') ch='*';
    for (auto &ch:s2) if (ch=='.') ch='*';
    int len=s1.length();
    int begin=0,end=len-1;
    while (!(s1[begin]=='#'||s2[begin]=='#')) {
        begin++;
        if (end<0||begin>=len) {
            cout<<0<<endl;
            return 0;
        }
    }
    while (!(s1[end]=='#'||s2[end]=='#')) {
        end--;
        if (end<0||begin>=len) {
            cout<<0<<endl;
            return 0;
        }
    }
    if (end<0||begin>=len) {
        cout<<0<<endl;
        return 0;
    }
    map<pair<string,string>,pair<int,string>> mp={
        {{"#*","#*"}, {0,"#*"}},
        {{"#*","*#"},{1,"##"}},
        {{"#*","##"}, {0,"##"}},
        {{"#*","**"},{1,"#*"}},

        {{"*#","#*"}, {1,"##"}},
        {{"*#","*#"},{0,"*#"}},
        {{"*#","##"}, {0,"##"}},
        {{"*#","**"},{1,"*#"}},

        {{"##","#*"}, {0,"#*"}},
        {{"##","*#"},{0,"*#"}},
        {{"##","##"}, {0,"##"}},
        {{"##","**"},{1,"taffy"}},

        {{"taffy","#*"}, {0,"#*"}},
        {{"taffy","*#"},{0,"*#"}},
        {{"taffy","##"}, {0,"##"}},
        {{"taffy","**"},{1,"taffy"}}
    };
    string prev;
    prev+=s1[begin];prev+=s2[begin];
    int ans=0;
    for (int i=begin+1; i<=end; i++) {
        string now;
        now+=s1[i];now+=s2[i];
        pair<string,string> p={prev,now};
        auto [k,change]=mp[p];
        ans+=k;
        prev=change;
    }
    cout<<ans;
    return 0;
}