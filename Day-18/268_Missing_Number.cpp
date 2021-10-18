// https://leetcode.com/problems/missing-number/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int i = 0;
        QuickSort(nums, 0, nums.size() - 1);
        for (i; i < nums.size(); i++)
        {
            if (nums[i] != i)
            {
                break;
            }
        }
        return i;
    }

    void swap(vector<int> &arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int partition(vector<int> &arr, int l, int r)
    {
        int pivot = arr[r];
        int i = l - 1;
        for (int j = l; j < r; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, r);
        return i + 1;
    }

    void QuickSort(vector<int> &arr, int l, int r)
    {
        if (l < r)
        {
            int pi = partition(arr, l, r);
            QuickSort(arr, l, pi - 1);
            QuickSort(arr, pi + 1, r);
        }
    }
};

int main()
{
    vector<int> a{0, 7, 4, 5, 6, 9, 2, 3, 8};
    Solution mis;
    cout << mis.missingNumber(a) << endl;
    return 0;
}