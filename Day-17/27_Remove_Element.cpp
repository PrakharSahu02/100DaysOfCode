// https : // leetcode.com/problems/remove-element//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int j = nums.size();
        if (j == 0)
            return j;
        if (j == 1)
        {
            if (nums[j - 1] == val)
            {
                nums.push_back(j - 1);
                j--;
            }
            return j;
        }
        for (int i = 0; i < j;)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[j - 1];
                nums[j-1]='_';
                j--;
            }
            else
                i++;
        }
        return j;
    }
};

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 2, 3, 3, 3};
    Solution rem;
    cout << rem.removeElement(arr, 2) << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}