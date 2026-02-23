#include<bits/stdc++.h>
using namespace std;
//#define int long long

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        multiset<int> remain;
        int max=-1;
        for(int i=0;i<len;i++) {
            int temp;
            cin>>temp;
            remain.insert(temp);
            max=max>temp? max:temp;
        }
        vector<int> ans;
        ans.push_back(max);
        remain.erase(remain.find(max));
        int cur=max;
        while (!remain.empty()) {
            int mem=-1;
            int delta=-1;
            for (auto num:remain) {
                int newDelta=(cur|num)-cur;
                if (newDelta>=delta) {
                    delta=newDelta;
                    mem=num;
                }
            }
            if (delta==0) {
                for (auto num:remain) {
                    ans.push_back(num);
                }
                break;
            }
            ans.push_back(mem);
            auto it=remain.find(mem);
            remain.erase(it);
            cur|=mem;
        }
        for (auto num:ans) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}