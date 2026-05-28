#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

// 两个数组做对组内元素做合并处理，这里用双端队列实现
// 直接遍历模拟

signed main() {
    int n,m;
    cin >> n >> m;
    deque<int> a;
    deque<int> b;
    
    for (int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    for (int i=0;i<m;i++) {
        int tmp;
        cin>>tmp;
        b.push_back(tmp);
    }

    int ans=0;
    while (!a.empty()&&!b.empty()) {
        if (a.front()==b.front()) {
            a.pop_front();
            b.pop_front();
        }
        else if (a.front()>b.front()) {
            int u=b.front();b.pop_front();
            int v=b.front();b.pop_front();
            b.push_front(u+v);
            ans++;
        }
        else if (b.front()>a.front()) {
            int u=a.front();a.pop_front();
            int v=a.front();a.pop_front();
            a.push_front(u+v);
            ans++;
        }
    }

    cout<<ans;
    return 0;
}