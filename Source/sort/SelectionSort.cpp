#include "SortingAlgorithm.h"

void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int pos_min = i;
        for (int j = i + 1; j < n; ++j)
            if (a[pos_min] > a[j])
                pos_min = j;
        swap(a[i], a[pos_min]);
    }
}