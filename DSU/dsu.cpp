#include<bits/stdc++.h>
using namespace std;
//Disjoint Set Union
// main functions -> 1) Find(x) = find the parent of x
//                   2) Union(x,y) = make union b/w x and y => making their parent same
// find in worst case will take O(n) time
//since union will use find it's time complexity will also O(n)

//Optimisations
//1. Path Compression Optimisation (find)
//2. Union by Rank (Union)
class dsu{
public:
vector<int> parent;
vector<int> size;
dsu(int n){
    parent.resize(n+1);
    size.resize(n+1);
    for(int i = 0;i <= n;i++){
        parent[i] = i;
        size[i] = i;
    }
}
bool formsCycle(int a, int b){
    return find_set(a) == find_set(b);
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

};


int main(){
    dsu d(4);
    d.union_sets(1,2);
    d.union_sets(2,3);
    //d.union_sets(3,4);
    cout<<d.formsCycle(4,3)<<" ";
}