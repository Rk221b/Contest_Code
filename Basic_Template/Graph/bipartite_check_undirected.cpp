#include<bits/stdc++.h>
#include<list>

using namespace std;


class Graph{

  int V;
  list<int> *l;

  public:

      Graph(int V){
        this->V = V;
        l = new list<int>[V];
      }

      void addEdge(int u, int v){

        l[u].push_back(v);
        l[v].push_back(u);
      }

      bool bipartite_helper(int node, int* visited, int parent, int color){

        visited[node] = color;

        /// 0 color represents not visited node
        /// 1 color represents visited node and colored with 1
        /// 2 color represents visited node and colored with 2

        for(auto nbrs:l[node]){
            if(visited[nbrs] == 0){
                bool cycle_mila = bipartite_helper(nbrs,visited,node, 3-color);

                if(cycle_mila){
                    return true;
                }
            }
            else if(nbrs != parent && color == visited[nbrs]){   /// back edge and odd length cycle
                return true;
            }
        }
        return false;
      }

      bool bipartite_detection(){

        int* visited = new int[V];

        for(int i=0;i<V;i++){
            visited[i] = 0;
        }

        return bipartite_helper(0,visited,-1,1);

      }


};


int main(){

  int n,e;  cin>>n>>e;

  Graph g(n);

  int u,v;

  for(int i=0;i<e;i++){
    cin>>u>>v;
    u--;
    v--;
    g.addEdge(u,v);
  }

/// If we get a cycle of odd length then graph is not bipartite else if its of even length then it is bipartite

  if(g.bipartite_detection()){
     cout<<"Not a Bipartite Graph"<<endl;
  }
  else{
    cout<<"Bipartite Graph"<<endl;
  }



return 0;
}
