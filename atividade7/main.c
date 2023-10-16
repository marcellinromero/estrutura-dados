#include <stdio.h>
#include "pilha.c"
#include "fila.c"

int main() {
    
    Pilha* pilha = criarPilha();

    empilhar(pilha, 1);
    empilhar(pilha, 2);
    empilhar(pilha, 3);

    imprimirPilha(pilha); 

    printf("Desempilhado: %d\n", desempilhar(pilha)); 
    imprimirPilha(pilha); 
    liberarPilha(pilha);

   
    Fila* fila = criarFila();

    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);

    imprimirFila(fila); 

    printf("Desenfileirado: %d\n", desenfileirar(fila));
    imprimirFila(fila); 

    liberarFila(fila);

    return 0;
}
