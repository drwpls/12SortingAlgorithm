#include "SortingAlgorithm.h"

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int i = 0, j = 0, k = 0;

    int *L = new int[n1];
    int *R = new int[n2];

    for (i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (j = 0; j < n2; ++j)
        R[j] = arr[m + j + 1];

    i = j = k = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[l + k] = L[i];
            k++;
            i++;
        }
        else
        {
            arr[l + k] = R[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[l + k] = L[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[l + k] = R[j];
        k++;
        j++;
    }
    delete[] L;
    delete[] R;
}

void PreMergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        PreMergeSort(arr, l, m);
        PreMergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void MergeSort(int arr[], int n)
{
    PreMergeSort(arr, 0, n - 1);
}