#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
//#define int long long

const int N = 5e5+5;
int arr[N],temp[N];
long long ans;

void mergesort(int l,int r) {
    if (l>=r) return;
    int mid=l+((r-l)>>1);
    mergesort(l,mid);
    mergesort(mid+1,r);
    int i=l,j=mid+1,k=l;
    // i对应左侧数组，j对应右侧数组，均有序
    while(i<=mid && j<=r) {
        if(arr[i]<=arr[j]) {
            temp[k++]=arr[i++];
        }
        else if (arr[i]>arr[j]) {// 出现逆序对
            temp[k++]=arr[j++];
            // 左侧出现大于arr[j]，说明当前所有左侧数组的数和arr[j]构成逆序对
            ans+=(mid-i+1);// 当前左侧数组剩余数数量
        }
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=r) temp[k++]=arr[j++];
    for(int p=l;p<=r;p++) arr[p]=temp[p];
}

signed main() {
    int len; cin >> len;
    for(int i=0;i<len;i++) cin >> arr[i];
    mergesort(0,len-1);
    cout<<ans<<endl;
    return 0;
}