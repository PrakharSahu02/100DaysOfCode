// https://leetcode.com/problems/happy-number/

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        if (n > 9)
        {
            while (n > 9)
            {
                n = check(n);
            }
        }
        if(n<10)
        {
            n = n * n;
            while (n > 9)
            {
                n = check(n);
            }
        }

        if (n == 1)
            return true;
        return false;
    }

    int check(int n)
    {
        if (n > 9)
        {
            return (check(n / 10) + ((n % 10) * (n % 10)));
        }
        else
        {
            return (n * n);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Solution add;
    cout << add.isHappy(n) << endl;
    return 0;
}