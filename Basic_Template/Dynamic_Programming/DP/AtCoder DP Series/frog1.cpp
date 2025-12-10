/*
https://atcoder.jp/contests/dp/tasks/dp_a
*/
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;  cin>>n;
    int height[n];
    int dp[n];

    for(int i=0;i<n;i++){
        cin>>height[i];
        dp[i] = 0;
    }

    dp[0] = 0;
    dp[1] = abs(height[1]-height[0]);

    for(int i=2;i<n;i++){
        dp[i] = min((abs(height[i]-height[i-1])+dp[i-1]), (abs(height[i]-height[i-2])+dp[i-2]));
    }

    cout<<dp[n-1]<<"\n";

return 0;
}
