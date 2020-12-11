#include "SortingAlgorithm.h"

void FlashSort(int arr[], int n)
{
    long long int min = ArrayMin(arr, n);
    long long int max = ArrayMax(arr, n);

    __int64 m = 0.43 * n;
    __int64* L = new __int64[m];
    memset(L, 0, m * sizeof(__int64));
    
    // L[k] number of class
    for (int i = 0; i < n; ++i)
    {
        __int64 k = static_cast<__int64>(((m - 1) * (double) (arr[i] - min)) / (max - min));
        // arr[i] is the member of k-class, L[k]++
        ++L[k];
    }

    // Like CountingSort, make L[k]: the last position of value k in class.
    L[0]--;
    for (int i = 1; i < m; ++i)
        L[i] += L[i - 1];       // after that, L[m-1] = n - 1

    // Move elements to right class
    long long int count = 0, i = 0, k = m - 1; // count: variable counts movements
    while (count < n)
    {
        while (i > L[k])
        {
            ++i;
            k = static_cast<__int64>(((m - 1) * ((double)(arr[i] - min)) / (max - min)));
        }

        int tmp = arr[i];

        while (i <= L[k])
        {
            k = static_cast<__int64>(((m - 1) * ((double)(tmp - min)) / (max - min)));
            swap(tmp, arr[L[k]]);
            L[k]--;
            count++;
        }
    }

    for (int j = 1; j < m; ++j)
        for (__int64 p = L[j] - 1; p > L[j - 1]; --p)
            if (arr[p] > arr[p + 1])
            {
                int tmp = arr[p];
                int t = p;
                while (tmp > arr[t + 1])
                {
                    arr[t] = arr[t + 1];
                    ++t;
                }
                arr[t] = tmp;
            }
    //delete[] L;
}