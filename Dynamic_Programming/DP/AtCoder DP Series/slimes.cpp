/*
https://atcoder.jp/contests/dp/tasks/dp_n
*/
#include<bits/stdc++.h>
#define ll long long int
#define inf 1e18
using namespace std;

ll dp[1000][1000];

ll cost_sum(ll arr[],ll a,ll b){

ll sum = 0;

for(ll i=a;i<=b;i++){
    sum += arr[i];
}
return sum;
}


ll matrix_mul(ll arr[], ll i, ll j){

 if(i >= j){
    return 0;
 }

 if(dp[i][j] != -1){
    return dp[i][j];
 }

 ll ans = inf;

 for(ll k=i;k<j;k++){
    ll temp = matrix_mul(arr,i,k) + matrix_mul(arr,k+1,j) + cost_sum(arr,i,k) + cost_sum(arr,k+1,j);
    ans = min(ans,temp);
 }
 return dp[i][j] = ans;
}


int main(){

    ll n;  cin>>n;
    ll arr[n];

    memset(dp,-1,sizeof(dp));

    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    ll ans = 0;

    ans = matrix_mul(arr,0,n-1);

    cout<<ans<<"\n";

return 0;
}
