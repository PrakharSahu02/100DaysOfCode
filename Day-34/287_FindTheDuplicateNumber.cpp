// https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int i = 0;
        for (i = 0; i < nums.size() - 1; i++)
        {
            if (!(nums[i] == i + 1))
            {
                if (nums[nums[i] - 1] == nums[i])
                {
                    break;
                }
                swap(&nums[i], &nums[nums[i] - 1]);
                i--;
            }
        }
        return nums[i];
    }

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

int main()
{
    vector<int> a = {1, 3, 6, 2, 5, 8, 7, 4, 7};
    Solution dup;
    cout << dup.findDuplicate(a) << endl;
    return 0;
}
