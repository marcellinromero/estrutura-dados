#include <stdio.h>
#include <string.h>

int busca_string(const char *array[], int tamanho, const char *busca) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(array[i], busca) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    const char *array[] = {"texto", "J", "EDA"};
    int tamanho = sizeof(array) / sizeof(array[0]);
    const char *busca = "EDO";
    int resultado = busca_string(array, tamanho, busca);
    printf("%d\n", resultado);
    return 0;
}