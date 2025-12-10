/*
https://www.codechef.com/LTIME84B/problems/TREDIFF
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;  cin>>t;

    while(t--){

            memset(depth,0,sizeof(depth));
            memset(Parent,-1,sizeof(Parent));

            int n,q;  cin>>n>>q;

            int arr[n+1];

            for(int i=1;i<=n;i++){
                cin>>arr[i];
                graph[i].clear();
            }


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

        int a,b;

        while(q--){

            cin>>a>>b;
            int lca = lca_sparse(a,b);

            int len_of_path = depth[a] + depth[b] - 2*depth[lca];

          //  cout<<"LCA "<<lca<<" "<<len_of_path<<endl;

            if(len_of_path > 100){  /// pigeonhole principle
                cout<<0<<endl;
            }
            else{
                vector<int> vec;
               // int ca = a, cb = b;
                while(a != lca)
                {
                    vec.push_back(arr[a]);
                    a = Parent[a][0];
                }
                while(b != lca)
                {
                    vec.push_back(arr[b]);
                    b = Parent[b][0];
                }

                vec.push_back(arr[lca]);
                sort(vec.begin(), vec.end());

            /*    for(auto ele:vec){
                    cout<<ele<<" ";
                }
                cout<<endl;   */

                int diff = 101;  /// Because any node can have a max value of 100

                for(int i=1;i<vec.size();i++){
                    diff = min(diff, vec[i] - vec[i-1]);
                }
                cout<<diff<<endl;
            }

        }
    }

return 0;
}
