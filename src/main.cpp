#include "benchmark.h"
#include <cstdlib>

int main() {
    const int size = 10000000;
    int* arr = new int[size];

    benchmark(arr, size);

    delete[] arr;
    return 0;
}
