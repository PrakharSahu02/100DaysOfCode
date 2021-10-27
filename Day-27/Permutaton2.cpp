#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void helper(vector<int> a, vector<vector<int>> &arr, int idx)
{
    if (idx == a.size())
    {
        arr.push_back(a);
        return;
    }

    for (int i = idx; i < a.size(); i++)
    {
        if (i != idx && a[i] == a[idx])
            continue;
        swap(a[i], a[idx]);
        helper(a, arr, idx + 1);
    }
}

vector<vector<int>> permute(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> arr;
    helper(nums, arr, 0);
    return arr;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    vector<vector<int>> ans = permute(a);
    for (auto v : ans)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
