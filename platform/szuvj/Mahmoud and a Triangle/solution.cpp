#include<bits/stdc++.h>
using namespace std;

int main() {
    int len;
    cin>>len;
    vector<int> v(len);
    for (int i=0;i<len;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int flag=0;
    for (int i = 2; i < len; i++) {
        if (v[i-2] + v[i-1] > v[i]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}