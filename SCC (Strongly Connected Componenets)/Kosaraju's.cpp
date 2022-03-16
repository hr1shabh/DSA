#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], int i, bool *vis, vector<int> &v){
    vis[i] = 1;
    for(auto j : graph[i]){
        if(!vis[j]){
            dfs(graph,j,vis,v);
        }
    }
    v.push_back(i);
}
void dfs2(vector<int> graph[], int i, bool *vis){
    vis[i] = 1;
    cout << i << " ";
    for(auto j : graph[i]){
        if(!vis[j]){
            dfs2(graph,j,vis);
        }
    }
}
void solve(vector<int> graph[], vector<int> rev[], int n){
    bool vis[n];
    memset(vis,0,n);
    vector<int> v;
    // step 1: ordering
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(graph,i,vis,v);
        }
    }
    //step 3: do dfs from r to l in v
    memset(vis,0,n);
    int k = 0;
    for(int i = n-1;i >= 0; i--){
        int node = v[i];
        if(!vis[node]){
            cout << (k++) << ": ";
            dfs2(rev,node,vis);
            cout << endl;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> graph[n];
    vector<int> rev[n];
    int m;
    cin >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        rev[b].push_back(a);
    }
    solve(graph,rev,n);
}