#include<bits/stdc++.h>
using namespace std;
int bfs(vector<vector<int>>& graph, int s, int t, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    while(!q.empty()){
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();
        for(int v=0; v<graph.size(); v++){
            if(parent[v] == -1 && graph[u][v] > 0){
                parent[v] = u;
                int new_flow = min(flow, graph[u][v]);
                if(v == t) return new_flow;
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}
int edwardcarp(vector<vector<int>>& graph, int s, int t){
    int maxflow = 0;
    vector<int> parent(graph.size());
    int flow;
    while((flow = bfs(graph, s, t, parent)) > 0){
        maxflow += flow;
        for(int v=t; v!=s; v=parent[v]){
            int u = parent[v];
            graph[u][v] -= flow;
            graph[v][u] += flow;
        }
    }
    return maxflow;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    int s, t;
    cin >> s >> t;
    cout << edwardcarp(graph, s, t) << endl;
    return 0;
}