#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

const int N=1e5+5;
int tree[4*N],d[N],lazy[4*N];

// 对区间进行建树，值为区间和
void build(int s,int t,int p) {
    if (s==t) {
        tree[p]=d[s];
        return;
    }
    int mid=s+((t-s)>>1);
    build(s,mid,p*2);
    build(mid+1,t,p*2+1);
    tree[p]=tree[p*2]+tree[p*2+1];
}

// c for delta
void update(int l,int r,int c,int s,int t,int p) {
    // 收敛到可表区间,进行修改，回溯，剪枝
    if (s>=l&&t<=r) {
        // 更新树对应值，打标记
        tree[p]+=(t-s+1)*c;
        lazy[p]+=c;
        return;
    }
    int mid=s+((t-s)>>1);
    if (lazy[p]) {
        // 有标记时
        tree[p*2]+=lazy[p]*(mid-s+1),lazy[p*2]+=lazy[p];
        tree[p*2+1]+=lazy[p]*(t-mid),lazy[p*2+1]+=lazy[p];
        lazy[p]=0;
    }
    if (l<=mid) {
        update(l,r,c,s,mid,p*2);
    }
    if (r>mid) {
        update(l,r,c,mid+1,t,p*2+1);
    }
    tree[p]=tree[p*2]+tree[p*2+1];// 递归将更新返回父节点
}

int getSum(int l,int r,int s,int t,int p) {
    // 收敛到可表区间
    if (s>=l&&t<=r) {
        return tree[p];
    }
    int mid=s+((t-s)>>1);
    // 有标记时（注：叶子节点的标记会一直存在，但是上方有递归处理
    if (lazy[p]) {
        tree[p*2]+=lazy[p]*(mid-s+1),lazy[p*2]+=lazy[p];
        tree[p*2+1]+=lazy[p]*(t-mid),lazy[p*2+1]+=lazy[p];
        lazy[p]=0;
    }
    int sum=0;
    if (l<=mid) {
        sum+=getSum(l,r,s,mid,p*2);
    }
    if (r>mid) {
        sum+=getSum(l,r,mid+1,t,p*2+1);
    }
    return sum;
}

signed main() {
    fio;
    int len,t;
    cin>>len>>t;
    for (int i=1;i<=len;i++) cin>>d[i];
    build(1,len,1);
    while (t--) {
        int q;
        cin>>q;
        if (q==1) {
            int x,y,k;
            cin>>x>>y>>k;
            update(x,y,k,1,len,1);
        }
        else if (q==2) {
            int x,y;
            cin>>x>>y;
            int ans=getSum(x,y,1,len,1);
            cout<<ans<<endl;
        }
    }
    return 0;
}