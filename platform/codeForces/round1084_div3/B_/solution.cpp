#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

// 如果这个数组已经是递增的，直接返回长度
// 反之，无论如何都存在方法（如eg1的扩展）将长度变为1

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        if (len==1) {
            cout<<"1"<<endl;
            continue;
        }
        bool flag=false;
        vector<int> v(len);
        for (int i=0;i<len;i++) {
            cin>>v[i];
        }
        vector<int> temp=v;
        sort(temp.begin(),temp.end());
        if (temp==v) {
            cout<<len<<endl;
        }
        else {
            cout<<"1"<<endl;
        }
    }
    return 0;
}