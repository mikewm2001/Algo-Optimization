#include "sort.h"
#include <thread>
#include <iostream>
#include <functional>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Standard quicksort algorithm
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Parallel quicksort algorithm
void quicksort_parallel(int arr[], int low, int high, int depth) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // cout << "Partition index: " << pi << " at depth: " << depth << endl;

        // Limit the number of threads created
        if (depth < 10) {
            // Use multithreading for faster execution
            std::thread left_thread(quicksort_parallel, std::ref(arr), low, pi - 1, depth + 1);
            std::thread right_thread(quicksort_parallel, std::ref(arr), pi + 1, high, depth + 1);

            left_thread.join();
            right_thread.join();
        } else {
            quicksort(arr, low, pi - 1);
            quicksort(arr, pi + 1, high);
        }
    }
}
