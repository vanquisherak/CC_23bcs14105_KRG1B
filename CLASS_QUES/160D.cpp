#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u,v,w,id;
};
const int N=200005;
vector<int>parent(N),sz(N);
int find(int x){
    return parent[x]==x?x:parent[x]=find(parent[x]);
}
void unite(int a,int b) {
    a=find(a);
    b=find(b);
    if(a!=b) {
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}
vector<pair<int,int>> g[N];
int tin[N],low[N],timer;
bool isBridge[N];
void dfs(int v,int pEdge) {
    tin[v]=low[v]=++timer;
    for(auto [to,id]:g[v]) {
        if(id==pEdge) continue;
        if(!tin[to]) {
            dfs(to,id);
            low[v]=min(low[v],low[to]);
            if (low[to]>tin[v]) {
                isBridge[id]=true;
            }
        }else{
            low[v]=min(low[v],tin[to]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<Edge> edges(m);
    for(int i=0;i<m;i++) {
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
        edges[i].id=i;
    }
    sort(edges.begin(),edges.end(),[](Edge &a,Edge &b) {
        return a.w<b.w;
    });
    for(int i=1;i<=n;i++) {
        parent[i]=i;
        sz[i]=1;
    }
    vector<string> ans(m);
    for(int i=0;i<m;) {
        int j=i;
        while(j<m && edges[j].w==edges[i].w) j++;
        map<int,int> comp;
        int idx=0;
        for(int k=i;k<j;k++) {
            int u=find(edges[k].u);
            int v=find(edges[k].v);
            if(u!=v) {
                if(!comp.count(u)) comp[u]=idx++;
                if(!comp.count(v)) comp[v]=idx++;
            }
        }
        for(int k=0;k<idx;k++) {
            g[k].clear();
            tin[k]=low[k]=0;
        }
        timer=0;
        for(int k=i;k<j;k++) {
            int u=find(edges[k].u);
            int v=find(edges[k].v);
            if(u==v){
                ans[edges[k].id]="none";
            }else{
                int cu = comp[u];
                int cv = comp[v];
                g[cu].push_back({cv, edges[k].id});
                g[cv].push_back({cu, edges[k].id});
            }
        }
        for(int k=0;k<idx;k++) {
            if(!tin[k]) dfs(k,-1);
        }
        for (int k=i;k<j;k++) {
            if(ans[edges[k].id]=="none") continue;
            if(isBridge[edges[k].id])
                ans[edges[k].id]="any";
            else
                ans[edges[k].id]="at least one";
        }
        for(int k=i;k<j;k++) {
            unite(edges[k].u,edges[k].v);
        }
        i=j;
    }
    for(int i=0;i<m;i++) {
        cout<<ans[i]<<"\n";
    }
    return 0;
}