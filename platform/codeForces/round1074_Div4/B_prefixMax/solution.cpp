#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while (t--) {
        int len;
        cin>>len;
        vector<int> num(len);
        int max=0,idx=-1;
        int sum=0;
        for (int i = 0; i < len; i++) {
            cin>>num[i];
            if (num[i]>max) {
                max=num[i];
                idx=i;
            }
            sum+=max;
        }
        swap(num[0],num[idx]);
        int ans=sum>max*len? sum:max*len;
        cout<<ans<<endl;
    }
    return 0;
}