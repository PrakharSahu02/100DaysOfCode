// https://leetcode.com/problems/search-insert-position/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int BinarySearch(vector<int> &arr, int num, int beg, int end)
    {
        int mid;

        if (beg > end)
        {
            return beg;
        }
        else
        {
            mid = beg + (end - beg) / 2;

            if (arr[mid] == num)
            {
                return mid;
            }
            else if (num > arr[mid])
            {
                return BinarySearch(arr, num, mid + 1, end);
            }
            else if (num < arr[mid])
            {
                return BinarySearch(arr, num, beg, mid - 1);
            }
        }
        return 0;
    }

    int searchInsert(vector<int> &nums, int target)
    {
        int s = 0, e = nums.size() - 1;
        return BinarySearch(nums, target, s, e);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr = {1, 2, 3, 4, 5, 9};
    Solution binary;
    cout << binary.searchInsert(arr, n)<<endl;
    return 0;
}