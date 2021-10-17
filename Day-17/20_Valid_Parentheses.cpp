// https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string &s)
    {
        stack<char> st;
        for (auto c : s)
        {
            if (c == ')')
            {
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
            }
            else if (c == '}')
            {
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
            }
            else if (c == ']')
            {
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
            }
            else
                st.push(c);
        }
        return st.empty();
    }
};

int main()
{
    string s = "(][";
    Solution check;
    cout << check.isValid(s) << endl;
    return 0;
}