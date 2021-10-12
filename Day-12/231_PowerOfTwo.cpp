// https://leetcode.com/problems/power-of-two/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
     return (n && !(n & n - 1));
    }
};

int main()
{int n;
    cin>>n;
    Solution p;
    cout<<p.isPowerOfTwo(n)<<endl;
    return 0;
}