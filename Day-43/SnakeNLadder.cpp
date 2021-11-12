#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int ladder, snake;
    cin >> ladder;
    map<int, int> lad, snak;
    for (int i = 0; i < ladder; i++)
    {
        int u, v;
        cin >> u >> v;
        lad[u] = v;
    }

    cin >> snake;
    for (int i = 0; i < snake; i++)
    {
        int u, v;
        cin >> u >> v;
        snak[u] = v;
    }

    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<int> vis(101, 0);
    vis[1] = true;

    while (!q.empty() && !found)
    {
        int sz = q.size();
        while (sz--)
        {
            int t = q.front();
            q.pop();
            for (int die = 1; die <= 6; die++)
            {
                if (t + die == 100)
                {
                    found = true;
                }
                if (t + die >= 100 && lad[t + die] && !vis[lad[t + die]])
                {
                    vis[lad[t + die]] = true;
                    if (t + die == 100)
                    {
                        found = true;
                    }
                    q.push(lad[t + die]);
                }
                else if (t + die >= 100 && snak[t + die] && !vis[snak[t + die]])
                {
                    vis[snak[t + die]] = true;
                    if (t + die == 100)
                    {
                        found = true;
                    }
                    q.push(snak[t + die]);
                }
                else if (t + die >= 100 && !snak[t + die] && !vis[t + die] && !lad[t + die])
                {
                    vis[t + die] = true;
                    if (t + die == 100)
                    {
                        found = true;
                    }
                    q.push(t + die);
                }
            }
        }
        moves++;
    }

    if (found)
    {
        cout << moves << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}