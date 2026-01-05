/*
 Problem Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/?envType=problem-list-v2&envId=graph

Cheapest Flights Within K Stops

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

*/

class Solution {
    typedef long long ll;
    int dp[10001][101];
    int next_city[10001][101];

    ll recursive(vector<vector<pair<int,int>>>& graph, int curr_node, int dst, int k){

        // base case
        if(curr_node == dst && k >= 0){
            return 0;
        }

        if(k < 0){
            return INT_MAX;
        }

        if (dp[curr_node][k] != -1) return dp[curr_node][k];

        ll ans = INT_MAX;
        next_city[curr_node][k] = -1;   // initialize

        for (auto &[next_node, price] : graph[curr_node]) {
            ll sub = recursive(graph, next_node, dst, k - 1);

            if (sub != INT_MAX && price + sub < ans) {
                ans = price + sub;
                next_city[curr_node][k] = next_node;  // store choice
            }
        }

        return dp[curr_node][k] = ans;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        int ans = INT_MAX;
        vector<vector<pair<int,int>>> graph(n);

        for(auto it : flights){
            int from  = it[0];
            int to    = it[1];
            int price = it[2];
            graph[from].push_back({to,price});
        }

        memset(dp,-1,sizeof(dp));
        memset(next_city, -1, sizeof(next_city));

        ans = recursive(graph,src,dst,k+1);

        /*

        next_city[u][k] = v;

        means:

        “From node u with k flights remaining, going to v gives the cheapest result.”

        */

        // 🔁 PATH RECONSTRUCTION
        vector<int> path;
        int node = src;
        int edges = k + 1;

        while (node != -1 && edges >= 0) {
            path.push_back(node);
            if (node == dst) break;
            node = next_city[node][edges];
            edges--;
        }

        // Print or use the path
        // Example: cout << "Path: ";
        // for (int x : path) cout << x << " ";

        return ans == INT_MAX ? -1 : ans;   
    }
};