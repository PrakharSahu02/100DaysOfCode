#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e9;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> jump(n, inf);
    if (a[0] == 0)
    {
        cout << inf << endl;
        return 0;
    }
    jump[0] = 0;
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i <= j + a[j])
            {
                jump[i] = min(jump[i], 1 + jump[j]);
            }
        }
    }
    cout << jump[n - 1] << endl;
    return 0;
}