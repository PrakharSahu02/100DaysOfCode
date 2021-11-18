#include <iostream>

using namespace std;

const int N = 1e5 + 2;
int toitent[N];

int main()
{
    for (int i = 0; i < N; i++)
    {
        toitent[i] = i;
    }
    for (int i = 2; i < N; i++)
    {
        if (toitent[i] == i)
        {
            for (int j = 2 * i; j < N; j += i)
            {
                toitent[j] *= i - 1;
                toitent[j] /= i;
            }
        }
    }

    cout << toitent[5] << endl;

    return 0;
}