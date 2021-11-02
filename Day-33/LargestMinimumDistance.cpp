#include <iostream>
#include <algorithm>

using namespace std;

bool isFeasible(int mid, int arr[], int n, int k)
{
    int pos = arr[0], elements = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
            if (elements == k)
            {
                return true;
            }
        }
    }
    return false;
}

int largestMinDistance(int arr[], int n, int k)
{
    sort(arr, arr + n);

    int result = -1;
    int left = 1, right = arr[n - 1];

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (isFeasible(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return result;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = 6;
    int k;
    cout << "Enter no. of parts : ";
    cin >> k;
    cout << "largest distance : " << largestMinDistance(arr, n, k) << endl;
    return 0;
}