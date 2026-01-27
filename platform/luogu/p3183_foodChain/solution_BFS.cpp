#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a,b,ans,mem[100001];
vector<int> v[100001];

int manbo(int x)
{
    if (mem[x]) return mem[x];
    if (!v[x].size()) return mem[x]=1;
    for (auto i:v[x]) mem[x]+=manbo(i);
    return mem[x];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
    }
    for (int i=1;i<=n;i++)
        if (!mem[i]&&v[i].size()) ans+=manbo(i);
    cout<<ans;
    return 0;
}