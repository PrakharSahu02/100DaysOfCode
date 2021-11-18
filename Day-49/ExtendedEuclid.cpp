#include <iostream>

using namespace std;

struct triplet
{
    int x, y, gcd;
};

triplet extendedEuclid(int a, int b)
{
    if (b == 0)
    {
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    triplet smallAns = extendedEuclid(b, a % b);
    triplet ans;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    ans.gcd = smallAns.gcd;
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    triplet ans = extendedEuclid(a, b);
    cout << ans.gcd << " " << ans.x << " " << ans.y << endl;
    return 0;
}