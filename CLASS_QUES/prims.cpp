#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> graph[n];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        vector<int> parent(n,-1);
        vector<bool> vis(n,false);
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            if(vis[node]) continue;
            vis[node]=true;
            for(auto it: graph[node]){
                int adjNode=it.first;
                int weight=it.second;
                if(!vis[adjNode] && dist[node]+weight<dist[adjNode]){
                    dist[adjNode]=dist[node]+weight;
                    parent[adjNode]=node;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<i<<" "<<dist[i]<<" "<<parent[i]<<"\n";
        }
    }
}