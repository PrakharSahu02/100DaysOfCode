#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    visited[src] = true;
    for (auto i : adj[src])
    {
        if (i != parent)
        {
            if (visited[i])
                return true;
            if (!visited[i] && isCycle(i, adj, visited, src))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);

    int x, y;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool cycle = false;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && isCycle(i, adj, visited, -1))
        {
            cycle = true;
        }
    }

    if (cycle)
        cout << "cycle present";
    else
        cout << "cycle not present";
    return 0;
}