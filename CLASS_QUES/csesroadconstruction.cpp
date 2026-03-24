#include<bits/stdc++.h>
using namespace std;
vector<int> parent, sz;
int find(int node){
    if(parent[node] == node) return node;
    return parent[node] = find(parent[node]);
}
bool unite(int u, int v, int &largest){
    int p1=find(u);
    int p2=find(v);
    if(p1==p2) return false;
    if(sz[p1]<sz[p2]) swap(p1, p2);
    parent[p2]=p1;
    sz[p1]+=sz[p2];
    largest=max(largest,sz[p1]);
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    parent.assign(n+1,0);
    sz.assign(n+1,1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    int components=n;
    int largest=1;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(unite(u,v,largest)) components--;
        cout<<components<<" "<<largest<<"\n";
    }
}
