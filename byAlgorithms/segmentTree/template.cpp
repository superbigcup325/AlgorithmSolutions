#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

template <typename T>
class segmentTree {
private:
    vector<T> tree,lazy;
    vector<T> *arr;
    int n,root,n4,end;

    void build(int s,int t,int p) {
        if (s==t) {
            tree[p]=(*arr)[s];
            return;
        }
        int mid=s+((t-s)>>1);
        build(s,mid,p*2);
        build(mid+1,t,p*2+1);
        tree[p]=tree[p*2]+tree[p*2+1];
    }

    void maintain(int s,int t,int p) {
       int mid=s+((t-s)>>1);
        if (s!=t&&lazy[p]) {
            tree[p*2]+=lazy[p]*(mid-s+1),lazy[p*2]+=lazy[p];
            tree[p*2+1]+=lazy[p]*(t-mid),lazy[p*2+1]+=lazy[p];
            lazy[p]=0;
        }
    }

    void RangeAdd(int l,int r,int c,int s,int t,int p) {
        if (s>=l&&t<=r) {
            tree[p]+=c*(t-s+1);
            lazy[p]+=c;
            return;
        }
        maintain(s,t,p);
        int mid=s+((t-s)>>1);
        if (l<=mid) RangeAdd(l,r,c,s,mid,p*2);
        if (r>mid) RangeAdd(l,r,c,mid+1,t,p*2+1);
        tree[p]=tree[p*2]+tree[p*2+1];
    }

    T RangeSum(int l,int r,int s,int t,int p) {
        // 收敛到可表区间
        if (s>=l&&t<=r) {
            return tree[p];
        }
        int mid=s+((t-s)>>1);
        T sum=0;
        maintain(s,t,p);
        if (l<=mid) sum+=RangeSum(l,r,s,mid,p*2);
        if (r>mid) sum+=RangeSum(l,r,mid+1,t,p*2+1);
        return sum;
    }

public:
    // 1-based
    explicit segmentTree(vector<T> v) {
        n=v.size()-1;
        n4=n*4;
        tree=vector<T>(n4,0);
        lazy=vector<T>(n4,0);
        arr=&v;
        end=n;
        root=1;
        build(1,end,1);
        arr=nullptr;// 释放
    }

    T rangeSum(int l,int r) {return RangeSum(l,r,1,end,root);}
    void rangeAdd(int l,int r,T delta) {return RangeAdd(l,r,delta,1,end,root);}
};

signed main() {

    return 0;
}