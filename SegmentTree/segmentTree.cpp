//height = log(n)
// query -> log(n), change -> log(n) 
#include<bits/stdc++.h>
using namespace std;

void buildTree(vector<int>& a,vector<int> &tree,int start,int end,int idx){
if(start == end){
    tree[idx] = a[start];
    return;
}
int mid = (start+end)/2;
buildTree(a,tree,start,mid,2*idx);
buildTree(a,tree,mid+1,end,idx*2+1);
tree[idx] = tree[2*idx]+tree[2*idx+1];
}

void updateTree(vector<int>& a,vector<int> &tree,int start,int end,int treeidx,int idx,int val){
if(start == end){
    a[idx] = val;
    tree[treeidx] = val;
    return;
}
int mid = (start+end)/2;
if(mid > idx){
    updateTree(a,tree,start,mid,treeidx*2,idx,val);
}else{
    updateTree(a,tree,mid+1,end,treeidx*2+1,idx,val);
}
tree[treeidx] = tree[2*treeidx]+tree[treeidx*2 + 1];
}

int query(vector<int>& tree,int start,int end,int treeidx,int left,int right){
//Completely Outside
if(start > right or end <left){
    return 0;
}
//completely inside
if(start>=left and end <= right){
    return tree[treeidx];
}
//partially inside
int mid = (start+end)/2;
int k1 = query(tree,start,mid,treeidx*2,left,right);
int k2 = query(tree,mid+1,end,treeidx*2+1,left,right);
return k1+k2;
}


int main(){
    int n;
    cin>>n;
vector<int> a(n),tree(4*n);
for(int i = 0;i<n;i++) cin>>a[i];
buildTree(a,tree,0,n-1,1);
for(int i = 1;i<4*n;i++)
cout<<tree[i]<<" "; cout<<endl;
updateTree(a,tree,0,n-1,1,3,10);
for(int i = 1;i<2*n;i++)
cout<<tree[i]<<" ";
cout<<query(tree,0,n-1,1,1,2);
}