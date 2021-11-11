#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int inf = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> dist(n + 1, inf);
    vector<vector<pair<int, int>>> graph(n + 1);

    int x, y, z;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;

        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }
    int source;
    cin >> source;
    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});
    while (!s.empty())
    {
        auto x = *s.begin();
        s.erase(x);
        for (auto it : graph[x.second])
        {
            if (dist[it.first] > dist[x.second] + it.second)
            {
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] < inf)
        {
            cout << dist[i] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }

    return 0;
}