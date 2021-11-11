#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 1e5 + 3;
vector<vector<int>> g[N];
int n, m, cost = 0;
vector<int> dist(N);
vector<int> parent(N);
vector<bool> vis(N);
const int inf = 1e9;

void primsMST(int source)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = inf;
    }

    set<vector<int>> s;
    dist[source] = 0;
    s.insert({0, source});
    while (!s.empty())
    {
        auto x = *s.begin();
        vis[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout << u << " " << v << " " << w << endl;
        cost += w;
        for (auto it : g[x[1]])
        {
            if (vis[it[0]])
            {
                continue;
            }
            if (dist[it[0] > it[1]])
            {
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    int x, y, z;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;

        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    primsMST(0);
    cout << cost;
    return 0;
}