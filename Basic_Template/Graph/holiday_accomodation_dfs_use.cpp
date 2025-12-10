/*
https://www.spoj.com/problems/HOLI/
*/
#include<bits/stdc++.h>
#include<list>
#define ll long long int
using namespace std;

class Graph{

  int V;
  list<pair<int, int> > *l;
  public:

      Graph(int V){
        this->V = V;
        l = new list< pair<int, int> >[V];
      }

      void addEdge(int u,int v,int wt){
          l[u].push_back(make_pair(v,wt));
          l[v].push_back(make_pair(u,wt));
      }


      int dfs_helper(int node, bool* visited, int* child, ll &ans){  /// This funtion will return number of child in its subtree

            visited[node] = true;
            child[node] = 1;


            for(auto nbr_pair:l[node]){

                int nbr = nbr_pair.first;
                int wt  = nbr_pair.second;

                if(!visited[nbr]){
                    child[node] += dfs_helper(nbr,visited,child,ans);
                    int a = child[nbr];
                    int b = V - a;
                    ans += min(a,b) * 2 * wt;
                }
            }
        return child[node];
      }


      ll dfs(){

        bool* visited = new bool[V];
         int* child = new int[V];

         for(int i=0;i<V;i++){
            visited[i] = false;
            child[i] = 0;
         }

         ll ans = 0;

         dfs_helper(0,visited,child,ans);

        return ans;
      }


};



int main(){

    int t;  cin>>t;
    int cnum = 1;

    while(t--){
        int n;  cin>>n;

        Graph g(n);

        int u,v,wt;

        for(int i=0;i<n-1;i++){
            cin>>u>>v>>wt;
            u--;
            v--;
            g.addEdge(u,v,wt);
        }

        ll ans = g.dfs();

        cout<<"Case #"<<cnum<<": "<<ans<<"\n";
        cnum++;
    }

return 0;
}
