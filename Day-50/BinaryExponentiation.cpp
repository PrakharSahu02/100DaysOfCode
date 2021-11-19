#include <iostream>

using namespace std;

const int N = 1e5 + 2, MOD = 1e9 + 7;

int toitent[N];

int power1(int a, int n)
{
    int ans = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        n = n >> 1;
    }
    return ans;
}

int power2(int a, int n)
{
    if (n == 0)
        return 1;
    int p = (power2(a, n / 2) % MOD);
    if (n & 1)
        return (((p * p) % MOD) * a) % MOD;
    else
        return (p * p) % MOD;
}

int main()
{
    int a, n;
    cin >> a >> n;
    a %= MOD;
    cout << power1(a, n) << endl;
    cout << power2(a, n) << endl;
    return 0;
}