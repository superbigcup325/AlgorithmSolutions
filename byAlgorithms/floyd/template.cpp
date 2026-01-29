#include<bits/stdc++.h>
using namespace std;

//weight can be less than 0, but no negative circle

vector<vector<int>> floyd(vector<vector<pair<int,int>>>& graph) {
    int v=graph.size()-1;
    vector<vector<int>> dis(v+1,vector<int> (v+1,INT_MAX));
    //diag
    for (int i=1;i<=v;i++) {
        dis[i][i]=0;
    }
    for (int from=1;from<=v;from++) {
        for (auto& [to,weight]:graph[from]) {
            dis[from][to]=min(dis[from][to],weight);//might repeat
            // if no direction add:
            //dis[to][from]=min(dis[to][from],weight);
        }
    }
    for (int mid=1;mid<=v;mid++) {
        for (int from=1;from<=v;from++) {
            if (dis[from][mid]==INT_MAX) {continue;}
            for (int to=1;to<=v;to++) {
                if (dis[from][mid]<INT_MAX&&dis[mid][to]<INT_MAX) {
                    //avoid exceed
                    long long newdis=dis[from][mid]+dis[mid][to];
                    dis[from][to]=dis[from][to]<newdis? dis[from][to]:newdis;
                }
            }
        }
    }
    //negative circle detect
    // for (int i=1;i<=v;i++) {
    //     for (int j=1;j<=v;j++) {
    //         if (dis[i][j]<0) cout<<"warning: negative circle detected"<<endl;
    //     }
    // }
    return dis;
}

int main() {
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>> graph(v+1);
    for (int i=1;i<=e;i++) {
        int from,to,weight;
        cin>>from>>to>>weight;
        graph[from].push_back({to,weight});
    }
    vector<vector<int>> dis=floyd(graph);
    for (int i=1;i<=v;i++) {
        for (int j=1;j<=v;j++) {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}