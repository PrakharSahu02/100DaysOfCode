#include <iostream>
#include <string>

using namespace std;

void substr(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);
    substr(ros, ans);
    substr(ros, ans + ch);
}

int main()
{
    string str = "ABC";
    substr(str, "");
    return 0;
}
