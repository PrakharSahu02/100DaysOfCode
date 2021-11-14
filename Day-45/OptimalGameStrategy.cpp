#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e9;
vector<int> a;
int dp[100][100];

int solve(int i, int j)
{
    if (i == j)
    {
        return a[i];
    }
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int l = a[i] + min(solve(i + 2, j), solve(i + 1, j - 1));
    int r = a[i] + min(solve(i, j - 2), solve(i + 1, j - 1));
    return dp[i][j] = max(l, r);
}

int main()
{
    int n;
    cin >> n;
    a = vector<int>(n);

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << solve(0, n - 1) << endl;
    return 0;
}