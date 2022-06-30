//Time complexity - update - O(logn), query - O(logn)
//Space complexity - O(n)

#include<bits/stdc++.h>
using namespace std;

void update(int idx, int val, vector<int> &BIT, int n){
    for(; idx <= n; idx += idx&(-idx)){
        BIT[idx] += val;
    }
}

int query(int idx, vector<int> &BIT){
    int sum = 0;
    for(;idx > 0; idx -= idx&(-idx)){
        sum += BIT[idx];
    }
    return sum;
}

int main(){
    int n;
    cin >> n;

    vector<int> v(n+1);
    vector<int> BIT(n+1);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
        update(i, v[i], BIT, n);
    }

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(r,BIT) - query(l-1, BIT) << endl;
    }
}