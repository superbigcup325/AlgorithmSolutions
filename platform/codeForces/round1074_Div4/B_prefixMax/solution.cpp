#include<bits/stdc++.h>
using namespace std;

// 依题意，只有一次交换，所以最大的数需要在第一位，故答案为最大数乘以长度

int main() {
    int t;
    cin>>t;
    while (t--) {
        int len;
        cin>>len;
        int x;
        int max=0;
        for (int i = 0; i < len; i++) {
            cin>>x;
            max=max>x? max:x;
            sum+=max;
        }
        cout<<max*len<<endl;
    }
    return 0;
}