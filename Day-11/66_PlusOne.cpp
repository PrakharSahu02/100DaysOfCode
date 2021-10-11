// https://leetcode.com/problems/plus-one/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 0;
        digits[digits.size() - 1] += 1;
        for (int i = (digits.size() - 1); i >= 0; i--)
        {
            while (digits[i] > 9)
            {
                digits[i] = digits[i] - 10;
                carry++;
                if(i==0 && carry==1){
                    digits.insert(digits.begin(),carry);
                    break;
                }
                digits[i - 1] = digits[i - 1] + carry;
            }
            
            carry=0;
        }
        return digits;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 9};
    Solution One;
    vector<int> v = One.plusOne(arr);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
