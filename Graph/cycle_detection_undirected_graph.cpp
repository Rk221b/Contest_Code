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

      bool cycle_helper(int node, bool* visited, int parent){

        visited[node] = true;

        for(auto nbrs:l[node]){
            if(!visited[nbrs]){
                bool cycle_mila = cycle_helper(nbrs,visited,node);

                if(cycle_mila){
                    return true;
                }
            }
            else if(nbrs != parent){  /// back edge concept
                return true;
            }
        }
        return false;
      }

      bool cycle_detection(){

        bool* visited = new bool[V];

        for(int i=0;i<V;i++){
            visited[i] = false;
        }

        return cycle_helper(0,visited,-1);

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

  if(g.cycle_detection()){
     cout<<"Graph has Cycle"<<endl;
  }
  else{
    cout<<"Graph doesn't have Cycle"<<endl;
  }



return 0;
}
