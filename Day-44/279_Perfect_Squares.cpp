// https : // leetcode.com/problems/perfect-squares/

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
class Solution
{
public:
    int numSquares(int n)
    {
        if(n==1||n==2){
            return n ;
        }
        
        vector<int> dp(n + 1, MOD);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; i * i + j <= n; j++)
            {
                dp[i * i + j] = min(dp[i * i + j], 1 + dp[j]);
            }
        }

        return dp[n];
    }
};

int main()
{
    int n;
    cin >> n;
    Solution ps;
    cout << ps.numSquares(n) << endl;
}
