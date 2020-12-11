#include "SortingAlgorithm.h"

void ShakerSort(int arr[], int n)
{
    bool haveswap = false;
    int l = 0, r = n - 1;
    while (l < r)
    {
        haveswap = false;
        for (int i = l; i < r; ++i)
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i + 1], arr[i]);
                haveswap = true;
            }
        if (haveswap == false)
            break;
        r--;

        for (int i = r; i > l; --i)
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i - 1], arr[i]);
                haveswap = true;
            }
        if (haveswap == false)
            break;
        l++;
    }
}