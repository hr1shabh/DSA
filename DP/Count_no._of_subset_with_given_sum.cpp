#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,q,n) for(int i=(int)q;i<n;i++)
#define pb push_back
#define debug(x) cout<<#x<<" "<<x<<endl;
#define ff first
#define ss second
#define sz(X) (int)X.size()
#define mp make_pair
#define endl "\n"
#define mem0(X) memset((X), 0, sizeof((X)))
#define mem1(X) memset((X), -1, sizeof((X)))

int dp[100][10000];
void solve(){
int n,k;
cin>>n>>k;
vector<int> v(n);
f(i,0,n){
    cin>>v[i];
}    

//Initialize
f(i,0,n+1){
	dp[i][0] = 1;
}

f(i,1,k+1) dp[0][i] = 0;

//Main Code
f(i,1,n+1){
f(j,1,k+1){
if(v[i-1] <= j){ 
	dp[i][j] = dp[i-1][j-v[i-1]] + dp[i-1][j]; 
}
else dp[i][j] = dp[i-1][j];
}
}

cout<<dp[n][k]<<endl;

}

int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
    return 0;
}

