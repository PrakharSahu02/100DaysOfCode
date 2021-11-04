#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    map<int, int>::iterator it = m.begin();

    for (it; it != m.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }
    return 0;
}