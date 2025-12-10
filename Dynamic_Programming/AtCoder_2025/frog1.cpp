#include<bits/stdc++.h>
using namespace std;

int memo_recursive(int idx, int n, vector<int> &heights, vector<int> &dp){

    /// Base case
    if(idx >= n) return 1e9;
    if(idx == n-1) return 0;

    /// DP Lookup
    if(dp[idx] != -1) return dp[idx];

    int take_one_step = 1e9, take_two_step = 1e9;
    if(idx+1 < n)
        take_one_step = abs(heights[idx+1] - heights[idx]) + memo_recursive(idx+1,n,heights,dp);
    if(idx+2 < n)
        take_two_step = abs(heights[idx+2] - heights[idx]) + memo_recursive(idx+2,n,heights,dp);

    return dp[idx] = min(take_one_step,take_two_step);

}

int main(){

    int n;
    cin>>n;

    vector<int> heights(n), dp(n,-1);

    for(int i=0;i<n;i++){
        cin>>heights[i];
    }

   // int ans = memo_recursive(0,n,heights,dp);

   // cout<<ans<<"\n";

   /// Iterative DP
   dp[0] = 0;

   for(int i=1;i<n;i++){
     if(i-1 >= 0)
        dp[i] = abs(heights[i-1] - heights[i]) + dp[i-1];
     if(i-2 >= 0)
        dp[i] = min(dp[i],abs(heights[i-2] - heights[i]) + dp[i-2]);
    }

    cout<<dp[n-1]<<"\n";

return 0;
}
