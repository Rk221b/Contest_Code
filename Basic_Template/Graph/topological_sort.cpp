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

      void addEdge(int u, int v){ /// Directed Edges
        l[u].push_back(v);
      }

      void topo_helper(int src, bool* visited, list<int> &ordering){

        visited[src] = true;

        for(auto nbrs:l[src]){
            if(!visited[nbrs]){
                topo_helper(nbrs,visited,ordering);
            }
        }

        ordering.push_front(src);
        return;

      }

      void topo(){

        bool* visited = new bool[V];
        list<int> ordering;

        for(int i=0;i<V;i++){
            visited[i] = false;
        }

        for(int i=0;i<V;i++){
            if(!visited[i]){
                topo_helper(i,visited,ordering);
            }
        }

        for(auto node: ordering){
            cout<<node<<" ";
        }
        cout<<endl;
      }


};


int main(){

  int n,e;  cin>>n>>e;

  Graph g(n);

  int u,v;

  for(int i=0;i<e;i++){
    cin>>u>>v;
    g.addEdge(u,v);
  }

  g.topo();


return 0;
}
