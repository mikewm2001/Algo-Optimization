#include "benchmark.cpp"

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    benchmark(arr, n);

    return 0;
}
