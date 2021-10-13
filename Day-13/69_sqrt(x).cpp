// https://leetcode.com/problems/sqrtx/

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int n) {
        long long x = n, y = 1;
        while(x - y > 0) {
            x = (x + y)/2;
            y = n/x;
        }
        return x;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sqrt;
    cout << sqrt.mySqrt(n) << endl;
    return 0;
}