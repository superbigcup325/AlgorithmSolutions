#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n<2) return false;
    for (int i=2; i<n; i++) {
        if (n%i==0) return false;
    }
    return true;
}


int main()
{
    int n;
    cin>>n;
    int sum=0;
    vector<int> arr(n);
    for (auto &x:arr) {
        cin>>x;
        sum+=x;
    }
    sort(arr.begin(),arr.end());
    int size=n/3;
    int idx=n-3;
    while (size--){
        sum-=arr[idx];
        idx-=2;
    }
    cout<<sum;
    return 0;
}