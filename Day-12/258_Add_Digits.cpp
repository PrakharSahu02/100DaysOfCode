// https://leetcode.com/problems/add-digits/

#include <iostream>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        int sum;
        do
        {
            sum = num % 10;
            num /= 10;
            num += sum;
        } while (num > 9);
        return num;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution add;
    cout << add.addDigits(n) << endl;
    return 0;
}