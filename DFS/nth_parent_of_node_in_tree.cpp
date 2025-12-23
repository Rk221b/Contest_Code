/*
Problem Link: https://cses.fi/alon/task/1687
*/

#include <bits/stdc++.h>
#define ll long long
#define fr(a, b) for (int i = a; i < b; i++)
using namespace std;

vector<int> tree[200001];
int up[200001][20];

void binary_lifting(int src, int par)
{
    up[src][0] = par;
    for (int i = 1; i < 20; i++)
    {
        if (up[src][i - 1] != -1)
            up[src][i] = up[up[src][i - 1]][i - 1];
        else
            up[src][i] = -1;
    }

    for (int child : tree[src])
    {
        if (child != par)
            binary_lifting(child, src);
    }
}

int ans_query(int node, int jump_required)
{
    if (node == -1 || jump_required == 0)
        return node;

    for (int i = 19; i >= 0; i--)
    {
        if (jump_required >= (1 << i))
        {
            return ans_query(up[node][i], jump_required - (1 << i));
        }
    }
}

int main()
{
    ll t, n, m, x, i, j, k, q;
    t = 1;
    while (t--)
    {
        cin >> n >> q;
        fr(2, n + 1)
        {
            cin >> x;
            tree[x].push_back(i);
            tree[i].push_back(x);
        }
        binary_lifting(1, -1);
        while (q--)
        {
            int node, k;
            cin >> node >> k;
            cout << ans_query(node, k) << '\n';
        }
    }
    return 0;
}