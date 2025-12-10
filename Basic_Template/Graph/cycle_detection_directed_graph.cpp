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
      }

      bool cycle_helper(int node, bool* visited, bool* stackk){

        visited[node] = true;
        stackk[node]  = true;

        for(auto nbrs:l[node]){
            if(!visited[nbrs]){
                bool cycle_mila = cycle_helper(nbrs,visited,stackk);

                if(cycle_mila){
                    return true;
                }
            }
            else if(stackk[nbrs] == true){  /// Node is visited and is in current path (back edge concept)
                return true;
            }
        }

        /// remove node from stack
        stackk[node] = false;

        return false;
      }

      bool cycle_detection(){

        bool* visited = new bool[V];
        bool* stackk = new bool[V];   /// This will tell if current node is part of current path

        for(int i=0;i<V;i++){
            visited[i] = false;
            stackk[i] = false;
        }

        return cycle_helper(0,visited,stackk);

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
