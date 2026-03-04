#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

// 两传送门之间的数不会增添，只会按顺序移动（环）
// 相应的，两端的数也有同样的规律
// 故我们把这个问题改为求两串数字典序最小的排序

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n,x,y;
        cin >> n >> x >> y;
        x--,y--;
        vector<int> outside;
        vector<int> inside;
        for (int i=0;i<n;i++) {
            int temp;
            cin >> temp;
            if (i<=x||i>y) outside.push_back(temp);
            else inside.push_back(temp);
        }
        if (!inside.empty()) rotate(inside.begin(),min_element(inside.begin(),inside.end()),inside.end());// 将中间旋转成最小值开始
        int m=inside.empty()? -1:inside[0];// 做基准
        auto it=outside.begin();
        while (it!=outside.end()&&*it<m) ++it;// 找最佳插入位置
        outside.insert(it,inside.begin(),inside.end());// 还原
        for (auto i:outside) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}