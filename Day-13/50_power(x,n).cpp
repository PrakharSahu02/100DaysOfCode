// https://leetcode.com/problems/powx-n/


#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
    double ans=1.0;
    long long num=n;
    if(num<0){
        num=-1*num;
    }
    while(num){
        if(num%2){
            ans=ans*x;
            num=num-1;
        }
        else{
            x=x*x;
            num=num/2;
        }
    }
    if(n<0){
        ans=(double)(1.0)/(double)(ans);
    }
    return ans;
}
};

int main()
{
    int n;
    double x;
    cin >>x>> n;
    Solution pow;
    cout << pow.myPow(x,n) << endl;
    return 0;
}