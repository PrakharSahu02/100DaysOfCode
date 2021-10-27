// https://leetcode.com/problems/find-peak-element/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int beg = 0, end = nums.size() - 1;
        if (nums.size() == 1)
        {
            return end;
        }
        for (int i = 1; i <= end; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                return i - 1;
            }
        }
        return end;
    }
};

int main()
{
    vector<int> a = {1, 2, 3, 4, 1, 3, 4, 6, 4, 5, 6};
    Solution peak;
    cout << peak.findPeakElement(a) << endl;
    return 0;
}