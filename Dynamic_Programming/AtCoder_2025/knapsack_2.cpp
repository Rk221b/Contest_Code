#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll memo_recursive(int idx, int n, int max_value, vector<ll> &weights, vector<ll> &value, vector<vector<ll>> &dp){

    /// Base case
    if(max_value == 0) return 0;
    if(idx >= n || max_value < 0) return 1e15;
   // if(row == n-1) return 0;

    /// DP Lookup
    if(dp[idx][max_value] != -1) return dp[idx][max_value];

    ll take = 1e15, not_take = 1e15;

    /// Not take case
    not_take = memo_recursive(idx+1,n,max_value,weights,value,dp);

    /// Take case
    if(value[idx] <= max_value){
        take = weights[idx] + memo_recursive(idx+1,n,max_value-value[idx],weights,value,dp);
    }


    return dp[idx][max_value] = min(take, not_take);

}

int main(){

    int n,w;
    cin>>n>>w;

    vector<ll> weights(n), value(n);

    int total_value = 0;

    for(int i=0;i<n;i++){
        cin>>weights[i]>>value[i];
        total_value += value[i];
    }

    /// dp[i][j] will denote minimum weight that will give us value j with i items selected
    vector<vector<ll>> dp(n,vector<ll>(total_value+1,-1));

   // cout<<total_value<<endl;
    for(int i=total_value;i>=0;i--){
      ll ans = memo_recursive(0,n,i,weights,value,dp);
      if(ans <= w) {
        cout<<i<<"\n";
        break;
      }
    }

   // cout<<ans<<"\n";



return 0;
}
