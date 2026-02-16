#include<bits/stdc++.h>
using namespace std;
//#define int long long
//最大团问题
//先建树找独立，再找最大相互独立组合

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        vector<array<int,3>> v(len+1);
        for(int i=1;i<=len;i++) {
            int a,b,c;
            cin>>a>>b>>c;
            v[i]={a,b,c};
        }
        vector<int> size(t+1,0);
        for (int i=1;i<=len;i++) {
            for (int j=i+1;j<=len;j++) {
                int a1=v[i][0],b1=v[i][1],c1=v[i][2];
                int a2=v[j][0],b2=v[j][1],c2=v[j][2];
                int a=a1-a2,b=b1-b2,c=c1-c2;
                if (a==0) {
                    if (b==0) {
                        if (c==0) {
                            continue;//题目保证不会
                        }
                        size[i]++;
                    }
                    continue;//不独立,b!=0
                }
                else {
                    int delta=b*b-4*a*c;
                    if (delta<0) {
                        size[i]++;//永不相交，独立
                    }
                }
            }
        }
        for (int i=1;i<=len;i++) {
            cout<<size[i]+1<<' ';
        }
    }
    return 0;
}