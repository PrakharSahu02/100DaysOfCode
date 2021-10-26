#include <iostream>
#include <string>

using namespace std;

string move(string s, char rmv)
{
    if (s.length() == 0)
        return "";
    char ch = s[0];
    string ans = move(s.substr(1),rmv);
    if (ch == rmv)
        return ans+ch;
    return ch + ans;
}

int main()
{
    string str = "aaabbbcccdee";
    char rmv;
    cin >> rmv;
    cout << move(str, rmv) << endl;
    return 0;
}
