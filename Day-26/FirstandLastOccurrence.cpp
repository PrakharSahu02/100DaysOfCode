#include <iostream>

using namespace std;

int firstocc(int arr[], int n, int i, int key)
{
    if (i == n)
        return -1;
    if (arr[i] == key)
        return i;

    return firstocc(arr, n, i + 1, key);
}

int lastocc(int arr[], int n, int i, int key)
{
    if (i == n)
        return -1;
    int restarray = lastocc(arr, n, i + 1, key);

    if (restarray != -1)
        return restarray;

    if (arr[i] == key)
        return i;

    return -1;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 9};
    cout << firstocc(a, 11, 0, 6) << endl;
    cout << lastocc(a, 11, 0, 6) << endl;
    return 0;
}
