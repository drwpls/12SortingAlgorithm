#include "SortingAlgorithm.h"

void ShellSort(int arr[], int n)
{
    int interval = 1;
    while (interval < n / 3)
        interval = interval * 3 + 1;

    while (interval > 0)
    {
        for (int i = interval; i < n; ++i)
        {
            int temp = arr[i];
            int j = i - interval;

            while (j >= 0 && temp < arr[j])
            {
                arr[j + interval] = arr[j];
                j -= interval;
            }
            arr[j + interval] = temp;
        }

        interval /= 3;
    }
}