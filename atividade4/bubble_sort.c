#include "bubble_sort.h"

void bubbleSort(int arr[], int n) {
    int temp;
    int swapped;

    do {
        swapped = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                // Swap arr[i-1] and arr[i]
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}
