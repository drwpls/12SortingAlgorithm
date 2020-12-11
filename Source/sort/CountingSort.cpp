#include "SortingAlgorithm.h"

void CountingSort(int arr[], int n)
{
    int min = ArrayMin(arr, n);
    int max = ArrayMax(arr, n);

    int range = max - min + 1;
    int *f = nullptr;
    f = new int[range];

    memset(f, 0, range * sizeof(int));

    // Count number of occurrences of i
    for (int i = 0; i < n; ++i)
        ++f[arr[i] - min];

    // f[t] is the last position of i in array.
    for (int i = 1; i < range; ++i)
        f[i] += f[i - 1];

    // Contain the sorted array
    int *brr = new int[n];

    // Sort
    for (int i = n - 1; i >= 0; --i)
    {
        brr[f[arr[i] - min] - 1] = arr[i];
        --f[arr[i] - min];
    }

    // Copy b to a
    for (int i = 0; i < n; ++i)
        arr[i] = brr[i];

    delete[] f;
    delete[] brr;
}