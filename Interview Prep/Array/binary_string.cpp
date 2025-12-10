/*
You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll countString(int n, int lastDigit,ll **dp){

    if(n == 1 || n == 0){
        return dp[n][lastDigit] = n;
    }
    if(dp[n][lastDigit] != -1){
        return dp[n][lastDigit];
    }

    if(lastDigit == 0){
        return dp[n][lastDigit] = (countString(n-1,0,dp)+countString(n-1,1,dp));
    }
    else{
        return dp[n][lastDigit] = countString(n-1,0,dp);
    }
}

int main(){

    int t; cin>>t;

    while(t--){

        int n;  cin>>n;

        ll** dp = new ll*[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = new ll[2];
            for(int j=0;j<2;j++){
                dp[i][j] = -1;
            }
        }

        cout<<countString(n,0,dp)+countString(n,1,dp)<<endl;
    }
return 0;
}
