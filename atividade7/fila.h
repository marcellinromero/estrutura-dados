#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int frente, traseira;
} Fila;

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = -1;
    fila->traseira = -1;
    return fila;
}

int estaVazia(Fila* fila) {
    return (fila->frente == -1);
}

int estaCheia(Fila* fila) {
    return (fila->traseira == MAX_SIZE - 1);
}

void enfileirar(Fila* fila, int item) {
    if (estaCheia(fila)) {
        printf("Erro: Fila cheia\n");
        return;
    }
    if (estaVazia(fila)) {
        fila->frente = 0;
    }
    fila->items[++(fila->traseira)] = item;
}

int desenfileirar(Fila* fila) {
    if (estaVazia(fila)) {
        printf("Erro: Fila vazia\n");
        return -1;
    }
    int item = fila->items[(fila->frente)++];
    if (fila->frente > fila->traseira) {
        fila->frente = fila->traseira = -1;
    }
    return item;
}

void imprimirFila(Fila* fila) {
    if (estaVazia(fila)) {
        printf("Fila vazia\n");
        return;
    }
    printf("Conteúdo da fila: ");
    for (int i = fila->frente; i <= fila->traseira; i++) {
        printf("%d ", fila->items[i]);
    }
    printf("\n");
}

void liberarFila(Fila* fila) {
    free(fila);
}
