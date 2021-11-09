// https://leetcode.com/problems/majority-element-ii/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        map<int, int>::iterator it = m.begin();
        int req = nums.size() / 3;

        for (it; it != m.end(); it++)
        {
            if (it->second > req)
            {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Solution hash;
    vector<int> ans = hash.majorityElement(a);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}