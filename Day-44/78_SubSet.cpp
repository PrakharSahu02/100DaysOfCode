// https://leetcode.com/problems/subsets/submissions/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sub;
        for (int i = 0; i < (1 << n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    sub.push_back(nums[j]);
                }
            }
            ans.push_back(sub);
            sub.clear();
        }
        return ans;
    }
};

int main()
{
    vector<int> n = {1, 2, 3};

    Solution code;
    vector<vector<int>> v = code.subsets(n);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j <v.size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
