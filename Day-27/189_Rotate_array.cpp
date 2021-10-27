// https://leetcode.com/problems/rotate-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (k >= nums.size())
        {
            k %= nums.size();
        }

        if (nums.size() == 1)
        {
            return;
        }

        reverse(nums.begin(), nums.end() - k);
        reverse(nums.begin() + (nums.size() - k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main()
{
    vector<int> a = {1, 2, 3, 3, 3, 4, 5};
    Solution rot;
    rot.rotate(a, 3);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}