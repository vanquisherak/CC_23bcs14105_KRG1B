#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void topologicalsort(vector<vector<int>>& edges, int v){
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto it:edges[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        ans.push_back(node);
        for(auto it:edges[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges(v);
    for(int i=0;i<e;i++){
        int u,to;
        cin>>u>>to;
        edges[u].push_back(to);
    }
    topologicalsort(edges,v);
    if(ans.size()==v) {
        cout<<"\nTrue";
    }else{
        cout<<"\nFalse";
    }
}
