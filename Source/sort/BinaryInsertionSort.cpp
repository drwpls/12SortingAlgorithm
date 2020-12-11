#include "SortingAlgorithm.h"

int Binary_Search(int arr[], int l, int r, int x)
{
    if (r > l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            return Binary_Search(arr, mid + 1, r, x);
        if (arr[mid] > x)
            return Binary_Search(arr, l, mid - 1, x);
    }

    // if not find extracly value, return position that arr[i] < x
    if (x > arr[l])
        return l + 1;
    else
        return l;
}

void BinaryInsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int temp = arr[i];
        int j = i - 1;

        int index = Binary_Search(arr, 0, j, temp);

        while (j >= index)
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = temp;
    }
}