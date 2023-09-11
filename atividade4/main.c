#include <stdio.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <lista de números>\n", argv[0]);
        return 1;
    }

    int n = argc - 1;
    int arr[n];

    for (int i = 1; i <= n; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    bubbleSort(arr, n);

    printf("Saída:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}
