#include "sort/SortingAlgorithm.h"
#include <direct.h>

#define MAX_SIZE 5

int Size[MAX_SIZE] = {3000, 10000, 30000, 100000, 300000};

int ArrayMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i)
        if (max < arr[i])
            max = arr[i];
    return max;
}

int ArrayMin(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; ++i)
        if (min > arr[i])
            min = arr[i];
    return min;
}

bool checkifsorted(int arr[], int n)
{
    bool checker = true;
    for (int i = 0; i < n - 1; ++i)
        if (arr[i] > arr[i + 1])
            checker = false;
    return checker;
}


template <class T, class Q>
__int64 sort_single_data(T sort_algrotihm, Q create_data_set, int*& arr, int i) 
{   // sort arr, size Size[i] with (Algorithm) sort_algrotihm and 
    // data generator from create_data_set
    // return runtime if sort successfully, else return -1

    create_data_set(arr, Size[i]);
    auto started = chrono::high_resolution_clock::now();
    sort_algrotihm(arr, Size[i]);
    auto done = chrono::high_resolution_clock::now();
    auto time = done - started;

    if (checkifsorted(arr, Size[i]))
        return (__int64)chrono::duration_cast<chrono::nanoseconds>(time).count();
    else
        return -1;
}
template <class T>
bool TestFor(T sort_algrotihm, string sort_algrotihm_name)
{
    // create a file that store data
    ofstream oustream("data/" + sort_algrotihm_name + ".csv"); 
    oustream << "Size (n),RandomData,SortedData,ReverseData,NearlySortedData" << endl;

    bool sort_ok = true;
    int *arr = nullptr;
    for (int i = 0; i < MAX_SIZE; ++i)     // size of Size[]
    {
        arr = new int[Size[i]];
        oustream << Size[i] << ",";
        __int64 run_time;

        // RandomData
        run_time = sort_single_data(sort_algrotihm, GenerateRandomData, arr, i);
        if (run_time >= 0)
            oustream << run_time << "," << flush;
        else
        {
            sort_ok = false;
            oustream << "Error" << ",";
        }

        // SortedData
        run_time = sort_single_data(sort_algrotihm, GenerateSortedData, arr, i);
        if (run_time >= 0)
            oustream << run_time << "," << flush;
        else
        {
            sort_ok = false;
            oustream << "Error" << ",";
        }

        // ReverseData
        run_time = sort_single_data(sort_algrotihm, GenerateReverseData, arr, i);
        if (run_time >= 0)
            oustream << run_time << "," << flush;
        else
        {
            sort_ok = false;
            oustream << "Error" << ",";
        }

        // NearlySortedData
        run_time = sort_single_data(sort_algrotihm, GenerateNearlySortedData, arr, i);
        if (run_time >= 0)
            oustream << run_time << "," << flush;
        else
        {
            sort_ok = false;
            oustream << "Error" << ",";
        }

        oustream << endl;
        if (arr)
        {
            delete[] arr;
            arr = nullptr;
        }
    }
    oustream.close();
    return sort_ok;
}

string sorting_algorithm_set[] = {"01SelectionSort",
                                    "02InsertionSort", 
                                    "03BinaryInsertionSort",
                                    "04BubbleSort",
                                    "05ShakerSort",
                                    "06ShellSort",
                                    "07HeapSort",
                                    "08MergeSort",
                                    "09QuickSort",
                                    "10CountingSort",
                                    "11RadixSort",
                                    "12FlashSort",
                                    };

int main()
{
    // Create directory
    int status = _mkdir("data");
    bool checker[12];

    checker[0] = TestFor(SelectionSort, "01SelectionSort");
    checker[1] = TestFor(InsertionSort, "02InsertionSort");
    checker[2] = TestFor(BinaryInsertionSort, "03BinaryInsertionSort");
    checker[3] = TestFor(BubbleSort, "04BubbleSort");
    checker[4] = TestFor(ShakerSort, "05ShakerSort");
    checker[5] = TestFor(ShellSort, "06ShellSort");
    checker[6] = TestFor(HeapSort, "07HeapSort");
    checker[7] = TestFor(MergeSort, "08MergeSort");
    checker[8] = TestFor(QuickSort, "09QuickSort");
    checker[9] = TestFor(CountingSort, "10CountingSort");
    checker[10] = TestFor(RadixSort, "11RadixSort");
    checker[11] = TestFor(FlashSort, "12FlashSort");

    bool errorcheck = false;
    for (int i = 0; i < 12; ++i)
        if (checker[i] == false)
        {
            cout << "Error in " << sorting_algorithm_set[i] << endl;
            errorcheck = true; 
        }

    if (!errorcheck)
        cout << "OK!";
    return 0;
}