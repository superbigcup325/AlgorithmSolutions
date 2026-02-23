#include<bits/stdc++.h>
using namespace std;

// 求包含每个节点i的最大团
// 团：顶点间两两有边
// 极大团定义：不是其他团的真子集
// 最大团定义：定点数量最多的极大团


vector<vector<bool>> adj;
int len;
vector<int> best;// 存储当前最大团


// R：当前正在构建的团（已选顶点集合）
// P：候选顶点集合（可以与 R 中所有顶点都相连的顶点）
// X：已排除顶点集合（已经尝试过且不能再加入的顶点）
// 极大团
void BronKerbosch(vector<int>& R,vector<int>& P,vecto<int>& X) {
    if (P.empty()) {
        if (R.size()>best.size()) best=R;
        else return;
    }

    if (R.size()+P.size()>best.size()) return;// 剪枝

    int u=-1;
    if (!P.empty()) u=P[0];
    else if (!X.empty()) u=X[0];
    else return;

    vector<int> P_Nu;
    for (auto v:P) {
        if (!adj[u][v]) P_Nu.push_back(v);
    }
    for (auto v:P_Nu) {
        vector<int> newR=R;
        newR.push_back(v);
    }
}

vector<vector<int>> solve(vector<vector<bool>>& adj) {
    vector<vector<int>> result;
    for (int i=1;i<=adj.size();i++) {

    }
}

int main() {
    return 0;
}