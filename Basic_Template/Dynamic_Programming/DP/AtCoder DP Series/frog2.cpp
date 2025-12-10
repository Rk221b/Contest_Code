/*
https://atcoder.jp/contests/dp/tasks/dp_b
*/
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,k;  cin>>n>>k;
    int height[n];
    int dp[n];

    for(int i=0;i<n;i++){
        cin>>height[i];
        dp[i] = INT_MAX;
    }

    dp[0] = 0;
   // cout<<0<<" ";
    for(int i=1;i<=k && i<n;i++){
        dp[i] = abs(height[i]-height[0]);
   //     cout<<dp[i]<<" ";
    }

    for(int i=k+1;i<n;i++){
        for(int j=i-1;j>=i-k && j>=0;j--){
            dp[i] = min(dp[i], (abs(height[i]-height[j])+dp[j]));
        }
      //  cout<<dp[i]<<" ";
    }
  //  cout<<endl;

    cout<<dp[n-1]<<"\n";

return 0;
}
