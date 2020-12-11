#ifndef SORTINGALGORITHM_H
#define SORTINGALGORITHM_H

// Define a printer to print variable' name.
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <chrono>
#include <string.h>
#include "DataGenerator.h"

using namespace std;

// declare function that return min/max of array.
void printer(const char *name, int value);
int ArrayMin(int arr[], int n);

int ArrayMax(int arr[], int n);

template <class T>
bool TestFor(T t, string filename);

bool checkifsorted(int arr[], int n);

void SelectionSort(int[], int);

void InsertionSort(int[], int);

int Binary_Search(int[], int, int, int);

void BinaryInsertionSort(int[], int);

void BubbleSort(int[], int);

void ShakerSort(int[], int);

void ShellSort(int[], int);

void HeapSort(int[], int);

void MergeSort(int[], int);

void QuickSort(int[], int);

void CountingSort(int[], int);

void RadixSort(int[], int);

void FlashSort(int[], int);

#endif