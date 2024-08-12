#include "benchmark.h"
#include <iostream>
#include <chrono>
#include "sort.cpp"
using namespace std;

// Benchmark function that tests both quicksort and quicksort_parallel
void benchmark(int arr[], int size) {
    // Copy the array
    int* arr_copy = new int[size];
    copy(arr, arr + size, arr_copy);

    // Benchmark standard quicksort
    auto start = chrono::high_resolution_clock::now();
    quicksort(arr, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Standard Quicksort: " << elapsed.count() << " seconds\n";

    // Benchmark parallel quicksort
    start = chrono::high_resolution_clock::now();
    quicksort_parallel(arr_copy, 0, size - 1);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Parallel Quicksort: " << elapsed.count() << " seconds\n";

    // Delete the copied array
    delete[] arr_copy;
}
