#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack)
{
    stack[src] = true;
    if (!visited[src])
    {
        visited[src] = true;
        for (auto i : adj[src])
        {
            if (!visited[i] && isCycle(i, adj, visited, stack))
            {
                return true;
            }
            if (stack[i])
                return true;
        }
    }
    stack[src] = false;
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
    }

    bool cycle = false;
    vector<int> stack(n, 0);
    vector<bool> visited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && isCycle(i, adj, visited, stack))
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