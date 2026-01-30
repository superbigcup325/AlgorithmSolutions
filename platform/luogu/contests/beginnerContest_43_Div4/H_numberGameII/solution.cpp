#include<bits/stdc++.h>
using namespace std;

//dancing line?

int a[4][4];
int b[4][4];

unordered_set<int> col(int i,int j) {
    unordered_set<int> result={1,2,3,4};
    for (int k=0;k<4;k++) {
        if (a[i][k]!=0)
        result.erase(a[i][k]);
    }
    return result;
}

unordered_set<int> row(int i,int j) {
    unordered_set<int> result={1,2,3,4};
    for (int k=0;k<4;k++) {
        if (a[k][j]!=0)
            result.erase(a[k][j]);
    }
    return result;
}

unordered_set<int> square(int i,int j) {
    unordered_set<int> result={1,2,3,4};
    int col=i==0||i==1? 0:2;
    int row=j==0||j==1? 0:2;
    for (int dx=0;dx<2;dx++) {
        for (int dy=0;dy<2;dy++) {
            if (a[col+dx][row+dy]!=0)
                result.erase(a[col+dx][row+dy]);
        }
    }
    return result;
}

unordered_set<int> repeat(unordered_set<int> c,unordered_set<int> b) {
    unordered_set<int> result;
    for (auto num:c) {
        if (b.count(num)) {
            result.insert(num);
        }
    }
    return result;
}

bool chk() {
    int flag=1;
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (a[i][j]==0) {
                flag=0;
            }
        }
    }
    return flag;
}

void re(){
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            a[i][j]=b[i][j];
        }
    }
}

int main() {
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            cin>>a[i][j];
            b[i][j]=a[i][j];
        }
    }
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (a[i][j]==0) {
                unordered_set<int> c=repeat(row(i,j),col(i,j));
                unordered_set<int> b=repeat(square(i,j),c);
                for (auto num:b) {
                    a[i][j]=num;
                    break;
                }
            }
        }
    }

    while (!chk()) {
        for (int i=3;i>=0;i--) {
            for (int j=3;j>=0;j--) {
                if (a[i][j]==0) {
                    unordered_set<int> c=repeat(row(i,j),col(i,j));
                    unordered_set<int> b=repeat(square(i,j),c);
                    for (auto num:b) {
                        a[i][j]=num;
                        break;
                    }
                }
            }
        }
    }
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            cout<<a[i][j];
            if (j==3) cout<<endl;
            else cout<<' ';
        }
    }
    return 0;
}