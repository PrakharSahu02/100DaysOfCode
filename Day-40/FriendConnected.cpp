#include <iostream>
#include <vector>

using namespace std;

vector<bool> vis;
vector<vector<int>> adj;
vector<int> component;

int get_comp(int idx)
{
    if (vis[idx])
        return 0;
    vis[idx] = true;
    int ans = 1;
    for (auto i : adj[idx])
    {
        if (!vis[i])
        {
            ans += get_comp(i);
            vis[i] = true;
        }
    }
    return ans;
}

int main()
{

    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);

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
            component.push_back(get_comp(i));
        }
    }

    long long ans = 0;
    for (auto i : component)
    {
        ans += i * (n - i);
    }

    cout << (ans / 2) << endl;
    return 0;
}