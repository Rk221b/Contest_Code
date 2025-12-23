const int MAXN = 200000;
const int LOG = 20;

vector<int> adj[MAXN];
int parent[LOG][MAXN];
int depth[MAXN];
int n;

void dfs(int v, int p)
{
    parent[0][v] = p;
    for (int u : adj[v])
    {
        if (u == p)
            continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
}

void build()
{
    for (int k = 1; k < LOG; k++)
    {
        for (int v = 0; v < n; v++)
        {
            if (parent[k - 1][v] == -1)
                parent[k][v] = -1;
            else
                parent[k][v] = parent[k - 1][parent[k - 1][v]];
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    for (int k = LOG - 1; k >= 0; k--)
    {
        if (parent[k][u] != -1 &&
            depth[parent[k][u]] >= depth[v])
        {
            u = parent[k][u];
        }
    }

    if (u == v)
        return u;

    for (int k = LOG - 1; k >= 0; k--)
    {
        if (parent[k][u] != parent[k][v])
        {
            u = parent[k][u];
            v = parent[k][v];
        }
    }

    return parent[0][u];
}

/*

8️⃣ Time Complexity

Depth equalization → O(log N)

Joint lifting → O(log N)

Total per query → O(log N)

9️⃣ Mental Model (VERY IMPORTANT)
Think of LCA like this:

Level both nodes

Lift them together

Stop just before collision

Return parent

🔑 One-line Interview Explanation

“First lift the deeper node to equal depth, then lift both nodes simultaneously using binary lifting until their parents match.”
*/