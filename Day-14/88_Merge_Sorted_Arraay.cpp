// https://leetcode.com/problems/merge-sorted-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int i = nums1.size() - 1, j = 0;
        while (j < n)
        {
            nums1[i] = nums2[j];
            i--;
            j++;
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main()
{
    vector<int> a = {1, 2, 5, 0, 0};
    vector<int> b = {2, 4};
    int m, n;
    m = a.size();
    n = b.size();
    Solution sort;
    sort.merge(a, m, b, n);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}