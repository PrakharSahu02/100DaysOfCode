#include <iostream>

using namespace std;

int KnapSack(int value[], int wt[], int n, int W)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return KnapSack(value, wt, n - 1, W);
    return max(KnapSack(value, wt, n - 1, W - wt[n - 1]) + value[n - 1], KnapSack(value, wt, n - 1, W));
}

int main()
{
    int n = 3, wt[] = {10, 20, 30}, value[] = {100, 50, 150}, W = 50;
    cout << KnapSack(value, wt, n, W) << endl;
    return 0;
}
