#include <iostream>
#include <climits>

using namespace std;

bool isPossible(int arr[], int n, int m, int min)
{
    int stdreq = 1, sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
        {
            return false;
        }
        if (sum + arr[i] > min)
        {
            sum = arr[i];
            stdreq++;
            if (stdreq > m)
            {
                return false;
            }
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

int AllocateMinPages(int arr[], int n, int m)
{
    int sum = 0;
    if (m > n)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    int start = 0, end = sum, ans = INT_MAX;
    while (start <= end)
    {
        int mid = start + (end - end) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = 6;
    int m;
    cout << "Enter no. of students : ";
    cin >> m;
    cout << "largest distance : " << AllocateMinPages(arr, n, m) << endl;
    return 0;
}