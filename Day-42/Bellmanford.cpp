#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    int x, y, z;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;

        edges.push_back({x, y, z});
    }
    int source;
    cin >> source;
    vector<int> dist(n, inf);
    dist[source] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        bool change = false;
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int z = e[2];
            change = true;
            dist[v] = min(dist[v], z + dist[u]);
        }
    }
    for (auto i : dist)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}