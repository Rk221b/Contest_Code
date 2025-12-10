/*
https://atcoder.jp/contests/dp/tasks/dp_h
*/
#include<bits/stdc++.h>
#include<vector>
#define mod 1000000007
using namespace std;

int main(){

    int n,m;  cin>>n>>m;
    int dp[n][m];
    char arr[n][m];

    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>arr[i][j];
      }
    }

    for(int i=0;i<n;i++){
        if(arr[0][i] == '.'){
            dp[0][i] = 1;
        }
        else{
            break;
        }
    }

    for(int i=0;i<m;i++){
        if(arr[i][0] == '.'){
            dp[i][0] = 1;
        }
        else{
            break;
        }
    }

    for(int i=1;i<n;i++){
      for(int j=1;j<m;j++){
        if(arr[i][j] == '#'){
            dp[i][j] = 0;
        }
        else{
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
        }
      }
    }

    cout<<dp[n-1][m-1]<<"\n";

return 0;
}

