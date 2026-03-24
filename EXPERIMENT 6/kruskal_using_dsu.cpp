#include<bits/stdc++.h>
using namespace std;
vector<int> parent(1e3,0);
vector<int> rnk(1e3,0);
int find(int node){
    if(parent[node]==node) return node;
    return parent[node]=find(parent[node]);
}
void make(int node){
    for(int i=1;i<=node;i++){
        parent[i]=i;
        rnk[i]=0;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        make(i);
    }
    vector<tuple<int,int,int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    int mst_weight=0;
    for(auto& edge: edges){
        int w,u,v;
        tie(w,u,v)=edge;
        int p1=find(u);
        int p2=find(v);
        if(p1!=p2){
            if(rnk[p1]<rnk[p2]){
                parent[p2]=p1;
                rnk[p1]++;
            }
            else{
                parent[p1]=p2;
                rnk[p2]++;
            }
            mst_weight+=w;
        }
    }
    cout<<"Weight of MST:"<<mst_weight<<endl;
}