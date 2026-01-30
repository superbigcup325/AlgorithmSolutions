#include<bits/stdc++.h>
using namespace std;

//找逆序对？

int main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        vector<int> v(len);
        for(int i=0;i<len;i++) {
            cin>>v[i];
        }
        if (is_sorted(v.begin(),v.end())) {
            cout<<-1<<endl;
            continue;
        }
    }
    return 0;
}