// https://leetcode.com/problems/gray-code/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> ans;
        for (int i = 0; i < 1 << n; i++)
            ans.push_back(i ^ (i >> 1));
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution code;
    vector<int> v = code.grayCode(n);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
        cout <<endl;
    return 0;
}
