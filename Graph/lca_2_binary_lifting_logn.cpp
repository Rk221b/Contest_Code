#include<bits/stdc++.h>
using namespace std;

const int N = 10005;
const int maxPar = log2(N);
vector<int> graph[N];
int Parent[N+1][maxPar], depth[N];

void dfs(int cur, int par){

    Parent[cur][0] = par;
    depth[cur] = depth[par] + 1;

    for(auto x:graph[cur]){
        if(x != par){
            dfs(x,cur);
        }
    }
    return;
}

void precomputeSparseMatrix(int n)
{

    /// Assuming 1 as root node
    dfs(1, -1);  /// This will fill the first column of our sparse table

    for (int i=1; i<maxPar; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            if (Parent[node][i-1] != -1)
                Parent[node][i] = Parent[Parent[node][i-1]][i-1];
        }
    }
}

int lca_sparse(int u, int v){  /// complexity O(Log(n))

    /// we are assuming depth of v to be always greater than u and to ensure that we do swapping
    if(depth[u] > depth[v]){
        swap(u,v);
    }

    int d = depth[v] - depth[u];

    while(d > 0){   /// this loop will run at max log(n) time
        int i = log2(d);
        v = Parent[v][i];
        d = d - (1 << i);
    }

    if(u == v){
        return u;
    }


    /// Now u and v are on same level

    for(int i=maxPar-1;i>=0;i--){
        if(Parent[u][i] != -1 && (Parent[u][i] != Parent[v][i])){
            u = Parent[u][i];
            v = Parent[v][i];
        }
    }


    return Parent[u][0];
}

int main(){

    memset(depth,0,sizeof(depth));
    memset(Parent,-1,sizeof(Parent));

    int n;  cin>>n;
    int x,y;

    for(int i=0;i<n-1;i++){
        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }



  /*  for(int i=1;i<=n;i++){
        cout<<i<<" "<<Par[i]<<" "<<depth[i]<<endl;
    }
  */

  precomputeSparseMatrix(n);


  cout<<lca_sparse(4,6)<<endl;
  cout<<lca_sparse(5,7)<<endl;

return 0;
}
