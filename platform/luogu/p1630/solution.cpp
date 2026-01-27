#include<bits/stdc++.h>
using namespace std;

int manbo(int x,int y,int p){
    int base=x;
    int ans=1;
    while (y>0){
        if (y&1) ans=(ans*base)%p;
        base=(base*base)%p;
        base%=p;
        y>>=1;
    }
    return ans%p;
}

int main(){
    int t;
    int p=1e4;
    cin>>t;
    while (t--){
        int a,b;
        cin>>a>>b;
        int table[p+1]={0};
        int full_sum=0;
        for (int i=1;i<=p;i++){
            table[i]=manbo(i,b,p);
            full_sum=(table[i]+full_sum)%p;
        }
        int full=a/p;
        int res=a%p;
        int ans=(full%p)*full_sum%p;
        for (int i=1;i<=res;i++){
            ans=(ans+table[i])%p;
        }
        cout<<ans<<endl;
    }
    return 0;
}