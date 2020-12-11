#include "SortingAlgorithm.h"

int partition(int arr[], int l, int r)
{
    int k = rand() % (r - l) + l;
    if (arr[k] > arr[r])
        swap(arr[k], arr[r]);
    swap(arr[l], arr[k]);
    int pivot = arr[l];
    int i = l, j = r + 1;
    do
    {
        do
            i++;
        while (arr[i] < pivot);
        do
            j--;
        while (arr[j] > pivot);
        swap(arr[i], arr[j]);
    } while (i < j);
    if (j < i)
        swap(arr[i], arr[j]);
    swap(arr[j], arr[l]);

    return j;
}

void PreQuickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int s = partition(arr, l, r);
        PreQuickSort(arr, l, s - 1);
        PreQuickSort(arr, s + 1, r);
    }
}

void QuickSort(int arr[], int n)
{
    PreQuickSort(arr, 0, n - 1);
}