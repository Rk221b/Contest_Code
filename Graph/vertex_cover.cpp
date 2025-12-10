/*
https://www.spoj.com/problems/PT07X/
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> graph[N];
int dp[N][2];   /// Here DP[i][0] represents answer in subtree of i if we take ith node in set and DP[i][1] represents answer if we don't include ith node

void dfs(int cur, int par){

    dp[cur][0] = 0;
    dp[cur][1] = 1;

    for(auto child:graph[cur]){
        if(child != par){
            dfs(child,cur);

            dp[cur][0] += dp[child][1];
            dp[cur][1] += min(dp[child][0],dp[child][1]);
        }
    }
}

int main(){

    int n;  cin>>n;

    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

   dfs(1,0);

   cout<<min(dp[1][0],dp[1][1])<<endl;

return 0;
}
