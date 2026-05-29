#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

const int mod = 1e9+7;
const int N = 1e5+5;

int mem[100][100];
int n,k;
int len;
int bits[100];

// limit表示是否能够随便填，true表示前缀跟n一样，false表示前缀跟n不同
// 即在当前状态是否在任一情况都能够不超过n
// pos:当前位置，cnt:当前为1数量
// 因为在前缀相同且满足个数为k的情况会很多（后续都是0的情况）
int dfs(int pos,int cnt,bool limit) {
    // 剪枝收敛
    if (cnt>k) return 0;
    if (pos==len) return cnt==k;
    // 前缀不同，计数已记忆化，直接剪枝
    if (!limit&&mem[pos][cnt]!=-1) {
        return mem[pos][cnt];
    }

    // 根据前缀做上界判断
    int max=limit? bits[pos]:1;
    int res=0;
    for (int i=0;i<=max;i++) {
        res+=dfs(pos+1,cnt+(i==1),limit&&i==max);
    }

    // 记忆化处理
    if (!limit) mem[pos][cnt]=res;

    return res;
}

signed main() {
    cin>>n>>k;
    len=0;

    // 转二进制，翻转，高位在左，低位在右
    while (n) {
        bits[len++]=(n&1);
        n>>=1;
    }
    for (int i=0;i<len/2;i++) {
        swap(bits[i],bits[len-1-i]);
    }

    memset(mem,-1,sizeof(mem));

    cout<<dfs(0,0,true);
    return 0;
}