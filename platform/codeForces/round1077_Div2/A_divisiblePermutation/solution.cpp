#include<bits/stdc++.h>
using namespace std;

//第一想法dfs正着做麻烦，超时
//对于最后两项，只能为{n,1}或{1,n}，再依次向前填充即可
//时间复杂度O(n),空间复杂度O(n)

int main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        vector<int> a;
        unordered_set<int> used;
        a.push_back(len);
        used.insert(a[0]);
        a.push_back(1);
        used.insert(a[1]);
        int prev=a[1];
        for (int i=len-2; i>0; i--) {
            if (prev-i>0&&prev<=len&&!used.count(prev-i)) {
                a.push_back(prev-i);
                used.insert(prev-i);
                prev=prev-i;
            }
            else {
                a.push_back(prev+i);
                used.insert(prev+i);
                prev=prev+i;
            }
        }
        for (int i=len-1;i>=0;i--) {
            cout<<a[i]<<" ";
        }
    }
    return 0;
}