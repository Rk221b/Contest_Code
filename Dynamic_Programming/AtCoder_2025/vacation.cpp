#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll memo_recursive(int day, int last_done_activity, int n, vector<vector<ll>> &activity, vector<vector<ll>> &dp){

    /// Base case
    if(day >= n) return 0;
   // if(row == n-1) return 0;

    /// DP Lookup
    if(last_done_activity != -1 && dp[day][last_done_activity] != -1) return dp[day][last_done_activity];

    int ans = 0, activity_done = 0;

    for(int i=0;i<3;i++){
        if(last_done_activity != i){
            activity_done = activity[day][i] + memo_recursive(day+1,i,n,activity,dp);
            ans = max(ans, activity_done);
        }
    }

    if(last_done_activity != -1) return dp[day][last_done_activity] = ans;
    return ans;

}

int main(){

    int n;
    cin>>n;

    vector<vector<ll>> activity(n,vector<ll>(3,0)), dp(n,vector<ll>(3,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
        cin>>activity[i][j];
        }
    }

    ll ans = memo_recursive(0,-1,n,activity,dp);

    cout<<ans<<"\n";



return 0;
}
