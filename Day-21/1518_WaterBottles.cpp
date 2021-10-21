// https://leetcode.com/problems/water-bottles/

#include <iostream>

using namespace std;

class Solution
{
public:
    int numWaterBottles(int bottles, int exchange)
    {
        int total = bottles;
        while (bottles >= exchange)
        {
            int left = bottles % exchange;
            total += bottles / exchange;
            bottles /= exchange;
            bottles += left;
        }
        return total;
    }
};

int main()
{
    int nb, ne;
    cin >> nb >> ne;
    Solution num;
    cout << num.numWaterBottles(nb, ne) << endl;
    return 0;
}