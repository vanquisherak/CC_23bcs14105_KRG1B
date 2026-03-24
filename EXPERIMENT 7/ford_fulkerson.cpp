#include<bits/stdc++.h>
using namespace std;
void dfs(int u,vector<vector<int>>& graph,vector<bool>& visited){
    visited[u]=true;
    for(int i=0;i<graph.size();i++){
        if(graph[u][i]>0 && !visited[i]){
            dfs(i,graph,visited);
        }
    }
}
int fordfulkerson(Vector<vector<int>>& graph, int s, int t){
    int maxflow=0;
    while(true){
        vector<bool> visited(graph.size(),false);
        dfs(s,graph,visited);
        if(!visited[t]) break;
        int pathflow=INT_MAX;
        for(int v=t;v!=s;){
            int u=-1;
            for(int i=0;i<graph.size();i++){
                if(visited[i] && graph[i][v]>0){
                    u=i;
                    break;
                }
            }
            pathflow=min(pathflow,graph[u][v]);
            v=u;
        }
        maxflow+=pathflow;
    }
    return maxflow;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v]=w;
    }
    int s,t;
    cin>>s>>t;
    cout<<fordfulkerson(graph,s,t)<<endl;
    return 0;
}