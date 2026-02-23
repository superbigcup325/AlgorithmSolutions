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
        vector<vector<bool>> graph(len+1,vector<bool>(len+1,false));
        for (int i=1;i<=len;i++) {
            for (int j=i+1;j<=len;j++) {
                auto [a1,b1,c1]=v[i];
                auto [a2,b2,c2]=v[j];
                int a=a1-a2,b=b1-b2,c=c1-c2;
                if (a==0) {
                    if (b==0) {
                        if (c==0) {
                            continue;//题目保证不会
                        }
                        graph[i][j]=true;
                    }
                    continue;//不独立,b!=0
                }
                else {
                    int delta=b*b-4*a*c;
                    if (delta<0) {
                        graph[i][j]=true;//永不相交，独立
                    }
                }
            }
        }
        vector<int> ans;
        for (int i=1;i<=len;i++) {
            vector<int> can;
            for (int j=1;j<=len;j++) {
                if (graph[i][j]) can.push_back(j);
            }

        }
    }
    return 0;
}