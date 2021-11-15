// https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int curr = 0, maxtillnow = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            if (curr < 0 && curr < nums[i])
                curr = nums[i];
            else
                curr += nums[i];
            maxtillnow = max(maxtillnow, curr);
        }
        return maxtillnow;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Solution sub;
    cout << sub.maxSubArray(a) << endl;

    return 0;
}