#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

pair<int,int> find(int begin, int end) {
    if (begin == end) return {begin,end};
    if (2*begin<=end) {
        return {begin,2*begin};
    }
    else {
        return {-1,-1};
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int begin,end;
        cin >> begin >> end;
        pair<int,int> ans = find(begin,end);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}