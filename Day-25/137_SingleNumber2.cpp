// https://leetcode.com/problems/single-number-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
   int singleNumber(vector<int>& nums) {
        int res=0;
        long long int p=1;
        for(int i=1;i<=32;i++){
            long long int setbit=0;
            for(int &x: nums){
                setbit+=(x&1);
                x>>=1;
            }
            setbit%=3;
            res+=(p*setbit);
            p*=2;
        }
        return res;
   }
};

int main()
{
    vector<int> v = {1, 2, 3, 1, 4,5,5,5,6,6,6,2, 3, 1, 2, 3, 4};
    Solution uni;
    cout << uni.singleNumber(v) << endl;
    return 0;
}