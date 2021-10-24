// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int pi = pivot(nums);
        if (pi == -1)
        {
            return BinarySearch(nums, target, 0, nums.size() - 1);
        }
        else
        {
            if (BinarySearch(nums, target, 0, pi))
            {
                return BinarySearch(nums, target, 0, pi);
            }
            else
            {
                return BinarySearch(nums, target, pi + 1, nums.size() - 1);
            }
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

    int BinarySearch(vector<int> arr, int num, int beg, int end)
    {
        int mid;

        if (beg > end)
        {
            return false;
        }
        else
        {
            mid = beg + (end - beg) / 2;

            if (arr[mid] == num)
            {
                return true;
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
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v1 = {5, 7, 8, 0, 1, 2, 3, 4};
    Solution srch;
    cout << srch.search(v1, n)<<endl;
    return 0;
}
