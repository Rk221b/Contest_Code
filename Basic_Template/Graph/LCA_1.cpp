#include<bits/stdc++.h>
using namespace std;

const int N = 10005;
vector<int> graph[N];
int Par[N], depth[N];

void dfs(int cur, int par){

    Par[cur] = par;

    for(auto x:graph[cur]){
        if(x != par){
            depth[cur] = depth[par] + 1;

            dfs(x,cur);
        }
    }
    return;
}


int lca_brute(int u, int v){  /// complexity O(n)

    if(u == v){
        return u;
    }

    /// we are assuming depth of u to be always greater than v and to ensure that we do swaping
    if(depth[u] < depth[v]){
        swap(u,v);
    }

    while(depth[u] > depth[v]){
        u = Par[u];
    }

    /// Now u and v are on same level
    while(u != v){
        u = Par[u];
        v = Par[v];
    }
    return u;
}

int main(){

    memset(depth,0,sizeof(depth));

    int n;  cin>>n;
    int x,y;

    for(int i=0;i<n-1;i++){
        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    /// Assuming 1 as root node
    dfs(1, 0);

  /*  for(int i=1;i<=n;i++){
        cout<<i<<" "<<Par[i]<<" "<<depth[i]<<endl;
    }
  */

 // cout<<lca_brute(18,16)<<endl;
  cout<<lca_brute(4,6)<<endl;
  cout<<lca_brute(5,7)<<endl;

return 0;
}
