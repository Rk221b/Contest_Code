/*
https://codeforces.com/contest/1249/problem/E
*/
#include<bits/stdc++.h>
using namespace std;

int dp[2][200005];   /// dp[0][i] represents coming to ith floor from stairs and dp[1][i] represents coming to ith floor from elevator

int main(){

    memset(dp,-1,sizeof(dp));
    int n,c;   cin>>n>>c;

    int a[n],b[n];

    for(int i=1;i<n;i++){
        cin>>a[i];
    }

    for(int i=1;i<n;i++){
        cin>>b[i];
    }

    dp[0][0] = 0; /// starting from stairs
    dp[1][0] = c; /// starting from elevator


    cout<<0<<" ";

    for(int i=1;i<n;i++){
        dp[0][i] = min(dp[0][i-1]+a[i], dp[1][i-1]+a[i]);
        dp[1][i] = min(dp[0][i-1]+b[i]+c, dp[1][i-1]+b[i]);

        cout<<min(dp[0][i],dp[1][i])<<" ";
    }


return 0;
}

