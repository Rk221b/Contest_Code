/*
https://atcoder.jp/contests/dp/tasks/dp_l
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 3004;

ll DP[N][N][2];

ll solve(ll arr[], int i, int j, int turn){

    if(i > j){
        return 0;
    }

    if(DP[i][j][turn] != -1){
        return DP[i][j][turn];
    }

    if(turn == 1){
        ll a1 = arr[i] + solve(arr,i+1,j,0);
        ll a2 = arr[j] + solve(arr,i,j-1,0);

        return DP[i][j][turn] = max(a1,a2);
    }
    else{
        ll x =  solve(arr,i+1,j,1);
        ll y =  solve(arr,i,j-1,1);

        return DP[i][j][turn] = min(x,y);
    }
}

int main(){

    int n;  cin>>n;
    ll arr[n];
    ll sum = 0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }

    memset(DP,-1,sizeof(DP));

    ll ans = solve(arr,0,n-1,1);

    cout<<ans-(sum-ans)<<endl;

return 0;
}
