#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[4][4];
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (a[i][j]==0) {
                unordered_set<int> appear;
                for (int k=0;k<4;k++) {
                    appear.insert(a[i][k]);
                }
                for (int k=1;k<=4;k++) {
                    if (!appear.count(k)) {
                        cout<<k;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}