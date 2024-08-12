#include "benchmark.h"
#include <cstdlib>

int main() {
    const int n = 10000000;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    benchmark(arr, n);

    delete[] arr;
    return 0;
}
