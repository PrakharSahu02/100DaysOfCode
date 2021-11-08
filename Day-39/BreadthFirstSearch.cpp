#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 2;

vector<int> adj[N];
bool vis[N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
    }

    int x, y;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> que;
    que.push(1);
    vis[1] = true;

    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        cout << node;
        vector<int>::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                que.push(*it);
            }
        }
    }

    return 0;
}