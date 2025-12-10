#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll memo_recursive(int idx, int n, int W, vector<ll> &weights, vector<ll> &value, vector<vector<ll>> &dp){

    /// Base case
    if(idx >= n || W <= 0) return 0;
   // if(row == n-1) return 0;

    /// DP Lookup
    if(dp[idx][W] != -1) return dp[idx][W];

    ll take = 0, not_take = 0;

    /// Not take case
    not_take = memo_recursive(idx+1,n,W,weights,value,dp);

    /// Take case
    if(weights[idx] <= W){
        take = value[idx] + memo_recursive(idx+1,n,W-weights[idx],weights,value,dp);
    }


    return dp[idx][W] = max(take, not_take);

}

int main(){

    int n,w;
    cin>>n>>w;

    vector<ll> weights(n), value(n);
    vector<vector<ll>> dp(n,vector<ll>(w+1,-1));

    for(int i=0;i<n;i++){
        cin>>weights[i]>>value[i];
    }

    ll ans = memo_recursive(0,n,w,weights,value,dp);

    cout<<ans<<"\n";



return 0;
}
