#include<bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>>& graph, vector<int>&dp){

    /// DP check
    if(dp[node] != -1) return dp[node];

    int ans = 0;
    for(auto nbr:graph[node]){
       // if(dp[nbr] == -1){
            ans = max(ans,1+dfs(nbr,graph,dp));
      //  }
    }
    return dp[node] = ans;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> graph(n);
    vector<int> dp(n,-1);
    int u,v,ans=0,tmp;

    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u-1].push_back(v-1);
    }

  //  cout<<"Test"<<endl;
    for(int i=0;i<n;i++){
        if(dp[i] == -1){
            tmp = dfs(i,graph,dp);
          //  cout<<i<<" "<<tmp<<endl;
        }
    }

    for(auto i:dp){
        ans = max(ans,i);
    }

    cout<<ans<<"\n";

return 0;
}
