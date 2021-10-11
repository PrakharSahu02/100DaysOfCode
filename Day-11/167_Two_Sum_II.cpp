// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> v;
        int i = 0, j = numbers.size() - 1;
        while (i != j)
        {
            if (numbers[i] + numbers[j] > target)
            {
                j--;
            }
            else if (numbers[i] + numbers[j] < target)
            {
                i++;
            }
            else
            {
                v.push_back(i + 1);
                v.push_back(j + 1);
                break;
            }
        }
        return v;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 9};
    Solution Sum;
    vector<int> v = Sum.twoSum(arr, 14);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
