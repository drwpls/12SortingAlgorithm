#include "SortingAlgorithm.h"

void BubbleSort(int arr[], int n)
{
    bool haveswap = false;
    for (int i = 0; i < n - 1; ++i)
    {
        haveswap = false;
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
                haveswap = true;
            }
        if (haveswap == false)
            break;
    }
}