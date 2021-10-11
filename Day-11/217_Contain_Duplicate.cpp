// https://leetcode.com/problems/contains-duplicate/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
 bool containsDuplicate(vector<int>& nums) {
     set<int> s(nums.begin(), nums.end());
	return nums.size() != s.size();
}
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    Solution Find;
    cout << Find.containsDuplicate(arr) << endl;
    return 0;
}