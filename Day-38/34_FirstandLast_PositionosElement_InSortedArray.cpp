// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> ans;
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (firstocc(nums, 0, n, target) != -1)
        {
            ans.push_back(firstocc(nums, 0, n, target));
            ans.push_back(lastocc(nums, 0, n, target));
            return ans;
        }
        return {-1, -1};
    }

    int firstocc(vector<int> arr, int i, int n, int key)
    {
        if (i >= n)
            return -1;

        int mid = i + (n - i) / 2;
        if (arr[mid] == key)
        {
            int m = mid;
            int l = firstocc(arr, 0, mid, key);
            if (l != -1 && l < m)
            {
                return l;
            }
            return m;
        }
        if (key > arr[mid])
        {
            return firstocc(arr, mid + 1, n, key);
        }
        return firstocc(arr, 0, mid, key);
    }

    int lastocc(vector<int> arr, int i, int n, int key)
    {
        if (i >= n)
            return -1;

        int mid = i + (n - i) / 2;
        if (arr[mid] == key)
        {
            int m = mid;
            int l = lastocc(arr, mid, n, key);
            if (l != -1 && l > m)
            {
                return l;
            }
            return m;
        }
        if (key > arr[mid])
        {
            return lastocc(arr, mid + 1, n, key);
        }
        return lastocc(arr, 0, mid, key);
    }
};

int main()
{
    vector<int> a = {3, 3, 3};
    Solution sr;
    vector<int> b = sr.searchRange(a, 3);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}