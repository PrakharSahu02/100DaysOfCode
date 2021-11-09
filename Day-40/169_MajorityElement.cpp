// https://leetcode.com/problems/majority-element/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        map<int, int>::iterator it = m.begin();
        int maxVal = INT_MIN;
        int key = 0;

        for (it; it != m.end(); it++)
        {
            if (it->second > maxVal)
            {
                key = it->first;
                maxVal = it->second;
            }
        }
        return key;
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
    cout << hash.majorityElement(a) << endl;

    return 0;
}