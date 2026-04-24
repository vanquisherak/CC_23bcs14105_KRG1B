#include<bits/stdc++.h>
using namespace std;
vector<int> arr(1e3);
vector<int> seg(4*1e3);
vector<int> lazy(4*1e3);
void build(int ind,int low,int high){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
}

int query(int ind,int low,int high,int l,int r){
    if(r<low || l>high){
        return INT_MIN;
    }
    if(l<=low && high<=r){
        return seg[ind];
    }
    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);
    return max(left,right);
}
void push(int ind,int low,int high){
    if(lazy[ind]!=0){
        seg[ind]+=lazy[ind];
        if(low!=high){
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }
}
int update(int ind,int low,int high,int l,int r, int val){
    push(ind,low,high);
    if(r<low || l>high){
        return seg[ind];
    }
    if(l<=low && high<=r){
        lazy[ind]+=val;
        push(ind,low,high);
        return seg[ind];
    }
    int mid=(low+high)/2;
    update(2*ind+1,low,mid,l,r,val);
    update(2*ind+2,mid+1,high,l,r,val);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
    return seg[ind];
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(0,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<endl;
    }
    int u;
    cin>>u;
    while(u--){
        int l,r,val;
        cin>>l>>r>>val;
        cout<<update(0,0,n-1,l,r,val)<<endl;
    }
    return 0;
}