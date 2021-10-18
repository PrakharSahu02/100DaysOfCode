// https://leetcode.com/problems/power-of-four/

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        int count = 0;
        if (n>0 && n && !(n & n - 1))
        {
            while (n)
            {
                n = n >> 1;
                count++;
            }
        }
        if (count % 2 != 0)
            return true;
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution four;
    cout << four.isPowerOfFour(n) << endl;
    return 0;
}
