#include<bits/stdc++.h>
using namespace std;
vector<int> parent(1e3,0);
vector<int> size(1e3,1);
int find(int node){
    if(parent[node]==node) return node;
    return parent[node]=find(parent[node]);
}
void make(int node){
    for(int i=1;i<=node;i++){
        parent[i]=i;
        size[i]=1;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        make(i);
    }
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        int p1=find(u);
        int p2=find(v);
        if(p1!=p2){
            if(size[p1]<size[p2]){
                parent[p2]=p1;
                size[p1]+=size[p2];
            }
            else{
                parent[p1]=p2;
                size[p2]+=size[p1];
            }
        }
    }
    int components=0;
    for(int i=1;i<=n;i++){
        if(parent[i]==i) components++;
    }
    cout<<"Total no of components:"<<components<<endl;
}