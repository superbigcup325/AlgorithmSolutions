#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

//根据题目要求，变为*的不影响其他变化，所以想到用栈解决

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        stack<char> s;
        for (int i=0;i<len;i++) {
            char temp;
            cin>>temp;
            if (temp=='*') continue;
            if (!s.empty()) {
                if (temp==s.top()) s.pop();// 注意stack.top()在栈为空时是未定义行为
                else s.push(temp);
            }
            else {
                s.push(temp);
            }
        }
        if (s.empty()) {
            cout<<"yes"<<endl;
        }
        else {
            cout<<"no"<<endl;
        }
    }
    return 0;
}