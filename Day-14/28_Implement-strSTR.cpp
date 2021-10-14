// https://leetcode.com/problems/implement-strstr/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {

        int found = haystack.find(needle);

        if (found != string::npos)
        {

            return found;
        }

        else
            return -1;
    }
};

int main()
{
    string s = "";
    string n = "";
    Solution check;
    cout << check.strStr(s, n) << endl;
    return 0;
}
