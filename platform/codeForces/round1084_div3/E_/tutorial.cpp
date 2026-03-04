#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

// 因为Alice先手，所以Alice能赢的情况下，Alice第一步就能决定输赢（保证分出一个质数使得数组不递增
//

int primebase(int x) {
    set<int> s;
    for (int i=2;i*i<=x;i++) {
        if (x%i==0) {
            s.insert(i);
            x/=i;
        }
    }// 找因数
    if (x>1) s.insert(x);
    if (s.size()>1) return -1;// x是合数
    if (s.size()==0) return 0;// x是1
    return *s.begin();// x是质数，返回它本身
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        vector<int> a(len);
        for (auto& i:a) cin>>i;
        vector<int> b(len);
        for (int i=0;i<len;i++) {
            b[i]=primebase(a[i]);
        }// 构建b，为
        if (is_sorted(a.begin(),a.end())) {
            cout<<"Bob"<<endl;
        }
        else if (min_element(b.begin(),b.end())==-1) {
            // 如果其中有x时合数，则必定能分出一个较大的质数保证数组不递增
            cout<<"Alice"<<endl;
        }
        else if (is_sorted(b.begin(),b.end())) {
            cout<<"Bob"<<endl;
        }
        else {
            cout<<"Alice"<<endl;
        }
    }
    return 0;
}