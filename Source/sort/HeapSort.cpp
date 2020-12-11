#include "SortingAlgorithm.h"

void Sift(int arr[], int l, int r)
{
    int x = arr[l];
    int i = l, j = 2 * i;
    while (j <= r)
    {
        if (j < r)
            if (arr[j] < arr[j + 1])
                j++; //arr[j] is smaller value than other
        if (arr[j] <= x)
            break;
        swap(arr[j], arr[i]);
        i = j;
        j = 2 * i;
        x = arr[i];
    }
}

void HeapSort(int arr[], int n)
{
    //create heap
    int l = n / 2;
    while (l >= 0)
    {
        Sift(arr, l, n - 1);
        l--;
    }

    int t = n - 1;
    while (t > 0)
    {
        swap(arr[0], arr[t]);
        t--;
        Sift(arr, 0, t);
    }
}