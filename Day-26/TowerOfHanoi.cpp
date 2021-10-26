#include <iostream>
#include <string>

using namespace std;

void towerofhanoi(int n, char scr, char dsc, char help)
{
    if (n == 0)
        return;
    towerofhanoi(n - 1, scr, help, dsc);
    cout << "Move from " << scr << " to " << dsc << endl;
    towerofhanoi(n - 1, help, dsc, scr);
}

int main()
{
    int n;
    cin>>n;
    char scr='A', dsc='C', help='B';
    towerofhanoi(n, scr, dsc, help);
    cout << endl;
    return 0;
}
