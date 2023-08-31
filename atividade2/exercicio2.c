#include <stdio.h>

void menor_maior_array(int array[], int tamanho, int *menor, int *maior) {
    if (tamanho <= 0) {
        *menor = *maior = 0;
        return;
    }
    
    *menor = *maior = array[0];  
    for (int i = 1; i < tamanho; i++) {
        if (array[i] < *menor) {
            *menor = array[i];
        }
        if (array[i] > *maior) {
            *maior = array[i];
        }
    }
}

int main() {
    int array[] = {5, 7, 9, 6};
    int tamanho = sizeof(array) / sizeof(array[0]);
    
    int menor, maior;
    menor_maior_array(array, tamanho, &menor, &maior);
    
    printf("Menor elemento: %d\n", menor);
    printf("Maior elemento: %d\n", maior);
    
    return 0;
}