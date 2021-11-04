#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> m;
    m[2] = 3;
    m[3] = 9;
    m[1] = 5;
    map<int, int>::iterator it = m.begin();
    for (it; it != m.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }
    return 0;
}