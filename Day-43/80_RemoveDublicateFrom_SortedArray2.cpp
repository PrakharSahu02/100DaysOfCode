// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = nums.size();
        int temp = 0;
        int ans = 0;

        if (count == 0 || count == 1)
            return count;

        for (int it = 0; it < nums.size() - 1; it++)
        {
            if (nums[it] == nums[it + 1])
            {
                it++;
                if (it < nums.size() - 1 && nums[it] == nums[it + 1])
                {
                    vector<int>::iterator start = nums.begin() + it;
                    temp = it;
                    while (temp < nums.size() - 1 && !(nums[temp] < nums[temp + 1]))
                    {
                        temp++;
                        ans++;
                    }
                    vector<int>::iterator end = nums.begin() + temp;
                    nums.erase(start, end);
                }
            }
        }
        return count - ans;
    }
};

int main()
{
    vector<int> arr = {1, 1, 1, 1, 1, 1, 1, 1};
    Solution array;
    cout << array.removeDuplicates(arr) << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}