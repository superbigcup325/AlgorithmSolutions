#include<bits/stdc++.h>
using namespace std;

int main() {
    int sum=0;
    int temp;
    while (cin>>temp) {
        sum+=temp;
    }
    if (sum<100) cout<<"Grey";
    else if (sum<120) cout<<"Blue";
    else if (sum<170) cout<<"Green";
    else if (sum<230) cout<<"Orange";
    else if (sum<=500) cout<<"Red";
    return 0;
}