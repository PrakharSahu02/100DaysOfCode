// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

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
        return count - ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 4, 5, 6, 6, 6, 6, 7, 8, 9, 10};
    Solution array;
    cout << array.removeDuplicates(arr) << endl;
    return 0;
}