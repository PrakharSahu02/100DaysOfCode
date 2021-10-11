// https://leetcode.com/problems/single-number/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
    int xorSum=0;
    for(int i=0;i<nums.size();i++){
        xorSum=xorSum^nums[i];
    }
    return xorSum;
    }
};

int main()
{
    vector<int> arr={1,2,3,4,5,4,3,2,1};
    Solution Find;
    cout<<Find.singleNumber(arr)<<endl;
    return 0;
}
