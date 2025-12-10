/*
https://atcoder.jp/contests/dp/tasks/dp_g
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> graph[100005];
int dp[100005];

int solve(int src){
    if(dp[src] != -1){
        return dp[src];
    }
    int leaf = 1;
    int best_child = 0;

    for(auto child:graph[src]){
        leaf = 0;
        best_child = max(best_child,solve(child));
    }
    if(leaf == 1){
        return dp[src] = 0;
    }
    else{
        return dp[src] = 1+best_child;
    }
}

int main(){

    int n,m;  cin>>n>>m;
    int x,y;

   // graph.clear();
    memset(dp,-1,sizeof(dp));

    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
    }

    int ans = 0;

    for(int i=1;i<=n;i++){
        ans = max(ans,solve(i));
    }

    cout<<ans<<"\n";

return 0;
}
