// https://leetcode.com/problems/first-bad-version/

#include <iostream>
#include <vector>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    bool isBadVersion(int version){};
    
    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;
        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid))
            {
                if (!isBadVersion(mid - 1))
                    return mid;
                else
                    right = mid - 1;
            }
            else
            {
                if (isBadVersion(mid + 1))
                    return mid + 1;
                else
                    left = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    Solution bs;
    cout << bs.firstBadVersion(n) << endl;
    return 0;
}