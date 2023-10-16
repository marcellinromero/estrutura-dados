#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Pilha;

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->top = -1;
    return pilha;
}

int estaVazia(Pilha* pilha) {
    return (pilha->top == -1);
}

int estaCheia(Pilha* pilha) {
    return (pilha->top == MAX_SIZE - 1);
}

void empilhar(Pilha* pilha, int item) {
    if (estaCheia(pilha)) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    pilha->items[++(pilha->top)] = item;
}

int desempilhar(Pilha* pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia\n");
        return -1;
    }
    return pilha->items[(pilha->top)--];
}

void imprimirPilha(Pilha* pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia\n");
        return;
    }
    printf("Conteúdo da pilha: ");
    for (int i = 0; i <= pilha->top; i++) {
        printf("%d ", pilha->items[i]);
    }
    printf("\n");
}

void liberarPilha(Pilha* pilha) {
    free(pilha);
}
