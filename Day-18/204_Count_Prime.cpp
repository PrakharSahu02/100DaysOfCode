// https://leetcode.com/problems/count-primes/

#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1)
        {
            return 0;
        }

        int prime[n], count = 0;
        for (int i = 0; i < n; i++)
        {
            prime[i] = 0;
        }

        for (long i = 2; i < n; i++)
        {
            if (prime[i] == 0)
            {
                long long j = i * i;
                for (j; j < n; j += i)
                {
                    prime[j] = 1;
                }
                count++;
            }
        }
        return count;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution cnt;
    cout << cnt.countPrimes(n) << endl;
    return 0;
}