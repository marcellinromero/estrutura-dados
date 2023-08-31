#include <stdio.h>

int somar_array(int array[], int tamanho) {
    int somar = 0;
    for (int i = 0; i < tamanho; i++) {
        somar += array[i];
    }
    return somar;
}

int main() {
    int array[] = {5, 7, 9, 6};
    int tamanho = sizeof(array) / sizeof(array[0]);
    int resultado = somar_array(array, tamanho);
    printf("somar dos elementos do array: %d\n", resultado);
    return 0;
}