// https://leetcode.com/problems/reverse-integer/

#include <iostream>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int ans = 0, rem, neg = 0;
        if (x < 0)
        {
            if (x < 0 && ans <= (INT_MIN - x) / 10)
                return 0;
            x *= -1;
            neg++;
        }
        while (x && x % 10 == 0)
        {
            x /= 10;
        }
        while (x != 0)
        {

            if (x > 0 && ans > (INT_MAX - x) / 10)
                return 0;

            rem = x % 10;
            ans = rem + ans * 10;
            x /= 10;
        }

        if (neg)
        {
            return -(ans);
        }
        return ans;
    }
};

// class Solution
// {
// public:
//     int reverse(int x)
//     {
//         int ans = 0, rem, neg = 0;
//         if (x < 0)
//         {
//             x *= -1;
//             neg++;
//         }
//         while (x && x % 10 == 0)
//         {
//             x /= 10;
//         }
//         while (x >= 10 || x <= -10)
//         {
//             rem = x % 10;
//             ans = rem + ans * 10;
//             x /= 10;
//         }

//          if (x < 0 && ans < (INT_MIN - x) / 10)
//             return 0;

//         if (x > 0 && ans > (INT_MAX - x) / 10)
//             return 0;

//         if (neg)
//         {
//             return -(ans);
//         }
//         return ans*10+x;
//     }
// };

int main()
{
    int n;
    cin >> n;
    Solution rev;
    cout << rev.reverse(n) << endl;
    return 0;
}