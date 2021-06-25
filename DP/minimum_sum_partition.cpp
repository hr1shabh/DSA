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


void solve(){
int n;
cin>>n;
vector<int> arr(n);
f(i,0,n){
    cin>>arr[i];
}    
 int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        bool dp[n+1][sum/2 + 1];
        int ans = sum;
        //initialize
        for(int i=0;i<=sum/2;i++){
            dp[0][i] = 0;
        }
        for(int i=0;i<=n;i++)
        dp[i][0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum/2;j++){
             if(arr[i-1] <= j){
                 dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j]; //always check for i,i-1
             }
             else dp[i][j] = dp[i-1][j];
            }
        }
// f(i,0,n+1){
//     f(j,0,sum/2 + 1){
//         cout<<dp[i][j]<<" ";
//     }cout<<endl;
// }

        for(int i=0;i<=sum/2;i++){
         //cout<<dp[n][i]<<" ";
            if(dp[n][i])
            ans=min(ans,sum - 2*i);
        }
        cout<<ans<<endl;

}

int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
   // cin>>t;
    while(t--){
    solve();
    }
    return 0;
}

