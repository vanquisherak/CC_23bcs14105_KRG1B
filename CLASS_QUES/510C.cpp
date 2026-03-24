#include <bits/stdc++.h>
using namespace std;
vector<int> adj[26];
int vis[26];
string result;
bool cycle=false;
void dfs(int u) {
    vis[u]=1;
    for (int v:adj[u]) {
        if (vis[v]==0) dfs(v);
        else if (vis[v]==1) cycle=true;
    }
    vis[u]=2;
    result+=(char)(u+'a');
}
int main() {
    int n;
    cin>>n;
    vector<string> words(n);
    for (int i=0;i<n;i++) cin>>words[i];
    for (int i=0;i<n-1;i++) {
        string a=words[i],b=words[i+1];
        int len=min(a.size(),b.size());
        bool found=false;
        for (int j=0;j<len;j++) {
            if (a[j]!=b[j]) {
                adj[a[j]-'a'].push_back(b[j]-'a');
                found=true;
                break;
            }
        }
        if(!found && a.size()>b.size()) {
            cout<<"Impossible\n";
            return 0;
        }
    }
    for (int i=0;i<26;i++) {
        if (vis[i]==0) dfs(i);
    }
    if (cycle) {
        cout<<"Impossible\n";
        return 0;
    }
    reverse(result.begin(),result.end());
    cout<<result<<endl;
    return 0;
}