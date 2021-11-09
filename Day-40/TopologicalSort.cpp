#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);

    int x, y;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        inDegree[y]++;
    }

    queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        cnt++;
        int x = pq.front();
        pq.pop();
        cout << x << " ";
        for (auto it : adj[x])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
            {
                pq.push(it);
            }
        }
    }
    return 0;
}