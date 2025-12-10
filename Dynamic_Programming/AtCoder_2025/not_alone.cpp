/*
https://codeforces.com/contest/2153/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cost(ll a, ll b, ll c){

    ll val_1 = abs(b-a) + abs(c-a);
    ll val_2 = abs(b-a) + abs(c-b);
    ll val_3 = abs(c-a) + abs(c-b);

    return min({val_1, val_2, val_3});
}

ll solve(vector<ll> &arr, int n, vector<ll> &dp){

     dp[0] = INT_MAX;
     dp[1] = abs(arr[1]-arr[0]);;

     for(int i=2;i<n;i++){
        /// block of 2
        dp[i] = dp[i-2] + abs(arr[i]-arr[i-1]);

        /// block of 3
        if((i-3) >= 0){
            dp[i] = min(dp[i], dp[i-3] + cost(arr[i],arr[i-1],arr[i-2]));
        }else{
            dp[i] = min(dp[i], 0 + cost(arr[i],arr[i-1],arr[i-2]));
        }
     }

     return dp[n-1];

}

int main(){

    int t;
    cin>>t;

    while(t--){

     int n; cin>>n;

     vector<ll> arr(n,0);
     vector<ll> dp(n,LONG_MAX);

     for(int i=0;i<n;i++){
        cin>>arr[i];
     }

     ll ans_1 = solve(arr,n,dp);

     /// Left rotate by 1 positions
     /// The element at v.begin() + 1 becomes the new first element.
     rotate(arr.begin(), arr.begin() + 1, arr.end());
     dp.clear();
     dp.assign(n,LONG_MAX);

     ll ans_2 = solve(arr,n,dp);

     /// Left rotate by 1 positions
     /// The element at v.begin() + 1 becomes the new first element.
     rotate(arr.begin(), arr.begin() + 1, arr.end());
     dp.clear();
     dp.assign(n,LONG_MAX);

     ll ans_3 = solve(arr,n,dp);

     cout<<min({ans_1,ans_2,ans_3})<<endl;

    }

return 0;
}

