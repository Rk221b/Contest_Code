/*
https://atcoder.jp/contests/dp/tasks/dp_d
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[101][100001];

ll solve(ll n, ll w, ll wt[], ll val[]){

    /// Base Case
    if(n <= 0){
        return 0;
    }

    /// Lookup
    if(dp[n][w] != -1){
       return dp[n][w];
    }

    if(wt[n-1] > w){ /// if weight is greater than capacity
        return dp[n][w] = solve(n-1,w,wt,val);
    }

    /// Two choices either to choose or not choose

    ll op1 = solve(n-1,w-wt[n-1],wt,val) + val[n-1];
    ll op2 = solve(n-1,w,wt,val);

    return dp[n][w] = max(op1,op2);

}


int main(){

    ll n,w;  cin>>n>>w;

    ll wt[n],val[n];

    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }

    memset(dp,-1,sizeof(dp));

    ll ans = solve(n,w,wt,val);

    cout<<ans<<"\n";

return 0;
}
