#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n = 8;
    vector<int> a = {1, 11, 2, 10, 4, 5, 2, 1};
    vector<int> frwd(n, 1);
    vector<int> bkwd(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                frwd[i] = max(frwd[i], 1 + frwd[j]);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[i] > a[j])
            {
                bkwd[i] = max(bkwd[i], 1 + bkwd[j]);
            }
        }
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, frwd[i] + bkwd[i] - 1);
    }

    cout << ans << endl;

    return 0;
}