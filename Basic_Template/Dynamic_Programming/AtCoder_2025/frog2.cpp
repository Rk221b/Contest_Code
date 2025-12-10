#include<bits/stdc++.h>
using namespace std;

int memo_recursive(int idx, int n, int k, vector<int> &heights, vector<int> &dp){

    /// Base case
    if(idx >= n) return 1e9;
    if(idx == n-1) return 0;

    /// DP Lookup
    if(dp[idx] != -1) return dp[idx];

    int ans = 1e9, take_step = 1e9;

    for(int i=1;i<=k;i++){
        if(idx+i < n){
            take_step = abs(heights[idx+i] - heights[idx]) + memo_recursive(idx+i,n,k,heights,dp);
            ans = min(ans, take_step);
        }
    }

    return dp[idx] = ans;

}

int main(){

    int n,k;
    cin>>n>>k;

    vector<int> heights(n), dp(n,-1);

    for(int i=0;i<n;i++){
        cin>>heights[i];
    }

   // int ans = memo_recursive(0,n,k,heights,dp);

   // cout<<ans<<"\n";

   /// Iterative DP
   fill(dp.begin(), dp.end(), 1e9);
   dp[0] = 0;

   for(int i=1;i<n;i++){
     for(int steps=1;steps<=k;steps++){
        if(i-steps >= 0)
            dp[i] = min(dp[i], abs(heights[i-steps] - heights[i]) + dp[i-steps]);
     }
    }

    cout<<dp[n-1]<<"\n";


return 0;
}
