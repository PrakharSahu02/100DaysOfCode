#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3 + 2;

int val[N], wt[N];
int dp[N][N];

int lis(int n, int w)
{
    if (w <= 0 || n <= 0)
    {
        return 0;
    }

    if (wt[n - 1] > w)
    {
        return lis(n - 1, w);
    }

    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (wt[n - 1] > w)
    {
        dp[n][w] = lis(n - 1, w);
    }
    else
    {
        dp[n][w] = max(lis(n - 1, w), lis(n - 1, w - wt[n - 1] + val[n - 1]));
    }

    return dp[n][w];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < N; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
    }

    int w;
    cin >> w;
    cout << lis(0, w) << endl;

    return 0;
}