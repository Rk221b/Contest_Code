/*
https://www.spoj.com/problems/COINS/
*/

/// This problem teaches that some problem are to be solved using Top Down Approach due to constrains as in Top down you go to desired states only

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll coins(ll n,ll dp[]){

    if(n <= 0){
        return 0;
    }

    if(n < 1000000){
        if(dp[n] != -1){
            return dp[n];
        }
        ll o1 = coins(n/2,dp);
        ll o2 = coins(n/3,dp);
        ll o3 = coins(n/4,dp);

    return dp[n] = max(n,(o1+o2+o3));
    }

    ll op1 = coins(n/2,dp);
    ll op2 = coins(n/3,dp);
    ll op3 = coins(n/4,dp);

    return max(n,(op1+op2+op3));
}

int main(){

  /* ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);  */

   ll n;
  while(cin>>n){
   ll dp[1000000];   /// We will memoize state only if n is less than 10^6 as we cant make array of size 10^9, so we will store limited states only

  // cout<<n<<endl;
   memset(dp,-1,sizeof(dp));

   cout<<coins(n,dp)<<endl;

    }

return 0;
}
