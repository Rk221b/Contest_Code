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

        map<T,int> distance;

        for(auto vertex: l){
            T node = vertex.first;
            distance[node] = INT_MAX;
        }

        queue<T> q;

        q.push(src);
        distance[src] = 0;

        cout<<"Source is : "<<src<<endl;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<"Distance of node "<<node<<" from source is : "<<distance[node]<<endl;
            list<T> tmp = l[node];

            for(auto nbrs:tmp){
                if(distance[nbrs] == INT_MAX){
                    distance[nbrs] = distance[node] + 1;
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
