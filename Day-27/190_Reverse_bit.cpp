// https://leetcode.com/problems/reverse-bits/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        string a = "";
        uint32_t ans = 0;
        for (int i = 1; i <= 32; i++)
        {
            int rem = getBit(n, 0);
            n = n >> 1;
            a = a + to_string(rem);
        }
        int power = 0;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            ans = ans + (stoi(a.substr(i, 1)) * pow(2, power));
            power++;
        }
        return ans;
    }

    int getBit(int n, int pos)
    {
        return ((n & (1 << pos)) != 0);
    }
};

int main()
{
    uint32_t a = 10;
    Solution bit;
    cout << bit.reverseBits(a) << endl;
    return 0;
}