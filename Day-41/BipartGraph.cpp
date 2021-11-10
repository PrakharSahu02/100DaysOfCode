#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> col;
vector<bool> vis;

bool bipart;

void color(int u, int curr)
{
    if (col[u] != -1 && col[u] != curr)
    {
        bipart = false;
        return;
    }
    col[u] = curr;
    if (vis[u])
    {
        return;
    }
    vis[u] = true;
    for (auto i : adj[u])
    {
        color(i, curr ^ 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n);
    col = vector<int>(n, -1);
    vis = vector<bool>(n, false);

    int x, y;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            color(i, 0);
        }
    }

    if (bipart)
        cout << "graph is bipartite";
    else
        cout << "graph is not bipartite";
    return 0;
}