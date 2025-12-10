#include<bits/stdc++.h>
#include<list>
#include<map>
#include<queue>

using namespace std;

template<typename T>

class Graph{

   map<T,list<T>> l;

   public:

       void addEdge(T x, T y, bool bidir = true){

            l[x].push_back(y);

            if(bidir){
                l[y].push_back(x);
            }
       }

       void printGraph(){

            for(auto Vertex: l){
                T node = Vertex.first;
                list<T> nbrs = Vertex.second;

                cout<<"Node :"<<node<<" -->";

                for(auto nbr: nbrs){
                    cout<<nbr<<" ,";
                }
                cout<<endl;
            }
       }

       void bfs(T src){

        map<T,bool> visited;

        for(auto vertex: l){
            T node = vertex.first;
            visited[node] = false;
        }

        queue<T> q;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            list<T> tmp = l[node];

            for(auto nbrs:tmp){
                if(!visited[nbrs]){
                    visited[nbrs] = true;
                    q.push(nbrs);
                }
            }
        }
     }

};

int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);


   // g.printGraph();
   g.bfs(0);

return 0;
}
