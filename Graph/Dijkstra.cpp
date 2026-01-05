#include<bits/stdc++.h>

using namespace std;

class Solution{

    public:
    vector<int> dijkstra(int src, int V, vector<vector<pair<int,int>>> &adjList){

        // Initialize distance array
        vector<int> dist(V,INT_MAX);

        dist[src] = 0; // source to source distance is 0

        // min heap priority queue that stores pair {dist,node} with min dist on top
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,src});

        while(!pq.empty()){

            auto it = pq.top();
            int d = it.first;
            int node = it.second;
            pq.pop();

            // Optimization: Skip stale entries
            if (d > dist[node])
                continue;

            // loop to all neighbours of node
            for(auto &[nbr_node, node_wt] : adjList[node]){

                if(dist[node]+node_wt < dist[nbr_node]){
                    dist[nbr_node] = dist[node]+node_wt;

                    pq.push({dist[nbr_node],nbr_node});
                }
            }
        }

        return dist;
    }
};

int main(){

    int V = 4;

    vector<vector<pair<int,int>>> adjList(V);
    vector<int> dist(V,INT_MAX);

    // Example edges
    adjList[0].push_back({1, 2});
    adjList[0].push_back({2, 4});
    adjList[1].push_back({2, 1});
    adjList[1].push_back({3, 7});
    adjList[2].push_back({4, 3});
    adjList[3].push_back({4, 2});

    Solution obj;

    dist = obj.dijkstra(0,V,adjList);

    for(int i=0;i<V;i++){
        cout<<"Distance of node = "<<i<<" from soruce 0 is = "<<dist[i]<<endl;
    }

    return 0;
}