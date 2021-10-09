#include <iostream>
using namespace std;

long long Merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    long long inv = 0;

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
            inv += n1 - i;
        }
    }

    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (i < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    return inv;
}

long long MergeSort(int arr[], int l, int r)
{
    long long inv = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;
        inv += MergeSort(arr, l, mid);
        inv += MergeSort(arr, mid + 1, r);
        inv += Merge(arr, l, mid, r);
    }
    return inv;
}

int32_t main()
{
    int arr[] = {3, 5, 6, 9, 1, 2, 7, 8};
    cout << MergeSort(arr, 0, 8) << endl;

    return 0;
}