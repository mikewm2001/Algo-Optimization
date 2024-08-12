#include "benchmark.h"
#include "sort.h"
#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;

// Function that initializes random arrays
void initializeArray(int arr[], int size) {
    // Initialize the array with random values
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

// Benchmark function that tests both quicksort and quicksort_parallel
void benchmark(int arr[], int size) {
    const int numTests = 10;
    double totalStandardTime = 0.0;
    double totalParallelTime = 0.0;

    for (int test = 0; test < numTests; test++) {
        // Initialize the array with random values for each test
        initializeArray(arr, size);

        // Copy the array with the same values
        int* arr_copy = new int[size];
        copy(arr, arr + size, arr_copy);

        // Benchmark standard quicksort
        auto start = chrono::high_resolution_clock::now();
        quicksort(arr, 0, size - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Standard Quicksort: " << elapsed.count() << " seconds\n";
        totalStandardTime += elapsed.count();

        // Benchmark parallel quicksort
        start = chrono::high_resolution_clock::now();
        quicksort_parallel(arr_copy, 0, size - 1, 0);
        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        cout << "Parallel Quicksort: " << elapsed.count() << " seconds\n";
        totalParallelTime += elapsed.count();

        // Delete the copied array
        delete[] arr_copy;
    }

    // Print average times
    cout << "Average Standard Quicksort Time: " << totalStandardTime / numTests << " seconds\n";
    cout << "Average Parallel Quicksort Time: " << totalParallelTime / numTests << " seconds\n";
    
}
