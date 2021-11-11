#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e+6;
vector<int> parent(N);
vector<int> sz(N);

void makeSet(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        makeSet(i);
    }
    int n, m;
    cin >> n >> m;

    int x, y, z;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;

        edges.push_back({x, y, z});
    }

    sort(edges.begin(), edges.end());
    int cost = 0;

    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        int z = i[2];
        int x = find_set(u);
        int y = find_set(v);

        if (x == y)
        {
            continue;
        }
        else
        {
            cout << u << " " << v << endl;
            cost += z;
            union_set(u, v);
        }
    }
    cout << cost;
    return 0;
}