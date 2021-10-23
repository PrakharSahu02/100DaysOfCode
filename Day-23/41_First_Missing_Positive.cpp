// https://leetcode.com/problems/first-missing-positive/

#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int>::iterator it = nums.begin();
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 1)
            {
                it++;
            }
            else
                break;
        }
        int counter = 1;
        for (it; it != nums.end();)
        {
            if (*it == counter)
            {
                counter++;
                it++;
            }
            else if (*it < counter)
            {
                it++;
            }
            else
                break;
        }
        return counter;
    }
};

int main()
{
    vector<int> arr = {0, 7, 9, 8, 3, 6, 4, 5, 1, 2, 10};
    Solution find;
    cout << find.firstMissingPositive(arr) << endl;
    return 0;
}
