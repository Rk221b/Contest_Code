/*
https://atcoder.jp/contests/dp/tasks/dp_e
*/
#include<bits/stdc++.h>
#define ll long long int
#define inf 1e9+1
using namespace std;


int main(){

    int n,w;  cin>>n>>w;
    int wt[n],val[n];

    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }

    /// Due to large constrains on weight 10^9 we can't use DP of n,wt so we will use value as it can be upto 1000 only
    /// DP[N][V] denotes that min weight required to get value V given N elements

    /// Base case will be DP[1][x] = w1 only if x = v1 else INT_MAX and DP[1][0] = 0 that is we dont choose any value so no weight is required

    int maxVal = n * 1000;

    int dp[n+1][maxVal+1];

    for(int i=0;i<=maxVal;i++){
        dp[1][i] = inf;
    }

    dp[1][0] = 0;
    dp[1][val[0]] = wt[0];


    for(int i=2;i<=n;i++){
        for(int j=0;j<=maxVal;j++){
            dp[i][j] = dp[i-1][j];
            if(val[i-1] <= j){
                dp[i][j] = min(dp[i][j],wt[i-1] + dp[i-1][j-val[i-1]]);
            }
        }
    }

    int ans = 0;

    for(int i=0;i<=maxVal;i++){
        if(dp[n][i] <= w)
            ans = i;
    }

    cout<<ans<<"\n";

return 0;
}
