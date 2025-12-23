/*
Problem Link: https://leetcode.com/problems/total-sum-of-interaction-cost-in-tree-groups/
*/

class Solution
{
    typedef long long ll;
    vector<int> node_group;

    long long dfs(int parent, int node, vector<vector<int>> &adj, vector<int> &visited, long long &ans, int target_group, vector<int> &group, vector<int> &total_group)
    {

        ll count_of_group = group[node] == target_group;
        visited[node] = 1;

        for (auto nbr : adj[node])
        {

            if (nbr == parent)
            {
                continue;
            }
            ll sub_tree_answer = dfs(node, nbr, adj, visited, ans, target_group, group, total_group);

            ans += sub_tree_answer * (total_group[target_group] - sub_tree_answer);

            count_of_group += sub_tree_answer;
        }

        return node_group[node] = count_of_group;
    }

public:
    long long interactionCosts(int n, vector<vector<int>> &edges, vector<int> &group)
    {

        long long ans = 0;
        vector<int> total_group(21, 0);
        vector<vector<int>> adj(n + 1);
        int u, v;

        for (int i = 0; i < n - 1; i++)
        {
            u = edges[i][0];
            v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (auto g : group)
        {
            total_group[g]++;
        }

        vector<int> visited(n, -1);
        node_group.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == -1)
            {

                for (int grp = 0; grp < 21; grp++)
                {
                    if (total_group[grp] >= 2)
                    {
                        node_group.assign(n, 0);
                        dfs(-1, i, adj, visited, ans, grp, group, total_group);

                        for (int k = 0; k < n; k++)
                        {
                            cout << "Node: " << k << " number of nodes of group " << grp << " in the subtree of " << k << " = " << node_group[k] << endl;
                        }
                    }
                }
            }
        }

        return ans;
    }
};

/*

Intuition
We are given a tree, so there is exactly one unique path between any two nodes.
For every unordered pair of nodes (u, v) that belong to the same group, we need to add the distance between them (number of edges on their path).

Instead of computing distances for all pairs directly (which would be too slow), we observe:

Every path between two nodes contributes 1 to the answer for each edge on that path.
So, we can reverse the thinking:
For each edge, count how many valid (u, v) pairs of the same group have their path passing through that edge.
Add this count to the total answer.
Thus, the problem becomes counting, for every edge and every group, how many same-group node pairs are separated by that edge.

Approach
Build the tree

Convert the edge list into an adjacency list for DFS traversal.
Count total nodes per group

Since group labels are in range 1..20, store how many nodes belong to each group in totalInGroup.
DFS with subtree counting

Root the tree at node 0.
For every node u, maintain counts[u][g] = number of nodes of group g in the subtree of u.
Edge contribution logic

While returning from child v to parent u, for each group g:
inSubtree = counts[v][g]
outsideSubtree = totalInGroup[g] - inSubtree
Any pair with one node inside v’s subtree and one outside must pass through edge (u, v).
Contribution of this edge for group g:
inSubtree * outsideSubtree
Add this value to the global answer.
Accumulate subtree counts

Add child subtree counts into the parent to propagate information upward.
This efficiently counts how many same-group paths include each edge.

Complexity
Time complexity: O(n × G)
where G = 20 (maximum number of groups)

Space complexity: O(n × G)


void dfs(int u, int p, int[] group) {
        counts[u][group[u]] = 1;

        for (int v : adj[u]) {
            if (v == p) continue;

            dfs(v, u, group);

            for (int g = 1; g <= 20; g++) {
                if (totalInGroup[g] < 2) continue;

                long inSubtree = counts[v][g];
                long outsideSubtree = totalInGroup[g] - inSubtree;

                totalCost += inSubtree * outsideSubtree;
                counts[u][g] += counts[v][g];
            }
        }
    }


*/