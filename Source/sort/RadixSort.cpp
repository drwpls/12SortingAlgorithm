#include "SortingAlgorithm.h"

int digit(int x, int k, int base = 10)
{
	while (k > 1)
	{
		x /= base;
		--k;
	}
	return x % base;
}

void sort(int arr[], int k, int n)
{
    int f[10];
    memset(f, 0, 10 * sizeof(int));
    int *b = new int[n];

    for (int i = 0; i < n; ++i)
    {
        f[digit(arr[i], k)]++;
    }

    f[0];
    for (int i = 1; i < 10; ++i)
    {
        f[i] += f[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int j = digit(arr[i], k);
        b[f[j] - 1] = arr[i];
        f[j]--;
    }
    for (int i = 0; i < n; ++i)
    {
        arr[i] = b[i];
    }
    delete[] b;
}

void RadixSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i)
        if (max < arr[i])
            max = arr[i];

    //int d = int(log(max) / log(10)) + 1;
    int d = log10(max) + 1;
    for (int k = 1; k <= d; ++k)
    {
        sort(arr, k, n);
    }
}