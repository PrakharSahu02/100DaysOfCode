// https://leetcode.com/problems/palindrome-number/

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        int r, temp;
        long sum = 0;
        temp = x;
        while (x > 0)
        {
            r = x % 10;
            sum = (sum * 10) + r;
            x = x / 10;
        }

        return (temp == sum);
    }
};

int main()
{
    int n;
    cout << "Enter no. ";
    cin >> n;
    Solution check;
    cout << check.isPalindrome(n)<<endl;
    return 0;
}