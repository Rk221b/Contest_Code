/*
We have to find min height that can be reached from subtree of x (Can use atmost 1 backedge if present).
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1000;

vector<int> graph[N];
int vis[N];
int depth[N];
int DP[N];

void dfs(int cur, int par, int dep){

    vis[cur] = 1;
    DP[cur] = dep;
    depth[cur] = dep;

    for(auto x:graph[cur]){
        if(vis[x] == 0){
            dfs(x,cur,dep+1);

            DP[cur] = min(DP[cur], DP[x]);
        }
        else if(x != par){  /// back edge
            DP[cur] = min(DP[cur], depth[x]);
        }
    }


}


int main(){

  int n,m;  cin>>n>>m;   /// n is number of nodes and m is number of edges
  int x,y;

  memset(vis,0,sizeof(vis));
  memset(depth,0,sizeof(depth));
  memset(DP,0,sizeof(DP));

  for(int i=0;i<m;i++){
    cin>>x>>y;

    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  dfs(1,0,0);

  for(int i=0;i<n;i++){
    cout<<i<<" "<<DP[i]<<endl;
  }

return 0;
}
