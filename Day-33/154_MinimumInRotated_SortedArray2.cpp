// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int pi = pivot(nums);
        if (pi == -1)
        {
            return nums[0];
        }
        else
        {
            return nums[pi + 1];
        }
    }

    int pivot(vector<int> arr)
    {
        int beg = 0, end = arr.size() - 1;
        if (arr.size() < 2)
        {
            return -1;
        }
        for (int i = 1; i <= end; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                return i - 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> a = {1, 2, 3, 3, 3, 4, 5};
    Solution rot;
    int ans = rot.findMin(a);
    cout << ans << endl;
    return 0;
}