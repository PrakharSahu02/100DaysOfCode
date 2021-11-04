#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, int> m;
    m[2] = 3;
    m[1] = 5;
    m[3] = 9;
    unordered_map<int, int>::iterator it = m.begin();
    for (it; it != m.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }
    return 0;
}