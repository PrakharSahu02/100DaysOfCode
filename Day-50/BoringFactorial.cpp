#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % p;
        }
        x = (x * x) % p;
        y = y >> 1;
    }
    return res;
}

int modInv(int a, int p)
{
    return power(a, p - 2, p);
}

int modFact(int n, int p)
{
    if (p <= n)
    {
        return 0;
    }
    int res = p - 1;
    for (int i = n + 1; i < p; i++)
    {
        res = (res * modInv(i, p)) % p;
    }
    return res;
}

int main()
{
    int n, p;
    cin >> n >>p;
    cout << modFact(n,p) << endl;
    return 0;
}