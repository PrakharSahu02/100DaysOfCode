#include <iostream>

using namespace std;

int tilingWays(int n)
{
    if (n == 0 || n == 1)
        return n;

    return tilingWays(n - 1) + tilingWays(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << tilingWays(n) << endl;
    return 0;
}
