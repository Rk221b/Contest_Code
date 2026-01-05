/*
 Problem Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/?envType=problem-list-v2&envId=graph

Cheapest Flights Within K Stops

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

*/

class Solution {
public:
    pair<int, vector<int>> findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);
        for (auto &f : flights) {
            graph[f[0]].push_back({f[1], f[2]});
        }

        const int INF = 1e9;

        // dist[node][stops]
        // dist[node][stops] = min cost to reach node using stops flights
        vector<vector<int>> dist(n, vector<int>(k + 2, INF));

        // parent[node][stops]
        // parent[node][stops] = previous node
        vector<vector<int>> parent(n, vector<int>(k + 2, -1));

        // min-heap: (cost, node, stops)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, src, 0});
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int cost = cur[0];
            int u = cur[1];
            int stops = cur[2];

            if (u == dst) break;
            if (stops == k + 1) continue;

            for (auto &[v, price] : graph[u]) {
                int newCost = cost + price;

                if (newCost < dist[v][stops + 1]) {
                    dist[v][stops + 1] = newCost;
                    parent[v][stops + 1] = u;
                    pq.push({newCost, v, stops + 1});
                }
            }
        }

        // find best cost among allowed stops
        int bestCost = INF;
        int bestStops = -1;

        for (int s = 0; s <= k + 1; s++) {
            if (dist[dst][s] < bestCost) {
                bestCost = dist[dst][s];
                bestStops = s;
            }
        }

        if (bestCost == INF) {
            return {-1, {}};
        }

        // 🔁 Path reconstruction
        vector<int> path;
        int node = dst;
        int s = bestStops;

        while (node != -1) {
            path.push_back(node);
            node = parent[node][s];
            s--;
        }

        reverse(path.begin(), path.end());

        return {bestCost, path};
    }
};
