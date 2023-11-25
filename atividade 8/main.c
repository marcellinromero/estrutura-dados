#include <stdio.h>
#include "lista.h"

int main() {
    No* lista;
    lista_inicializar(&lista);

    lista_inserir_no_i(lista, 0, 'A');
    lista_inserir_no_i(lista, 1, 'B');
    lista_inserir_no_i(lista, 2, 'C');
    lista_inserir_no_i(lista, 3, 'B');
    lista_inserir_no_i(lista, 4, 'D');

    char valor_busca = 'B';
    if (lista_verificar_existencia(lista, valor_busca)) {
        printf("O valor '%c' existe na lista.\n", valor_busca);
    } else {
        printf("O valor '%c' nao existe na lista.\n", valor_busca);
    }

    int ocorrencias = lista_verificar_ocorrencias(lista, valor_busca);
    printf("O valor '%c' ocorre %d vezes na lista.\n", valor_busca, ocorrencias);

    printf("Lista na ordem inversa: ");
    lista_imprimir_inversa(lista);
    printf("\n");

    lista_inserir_no_i(lista, 2, 'E');

    lista_remover_no_i(lista, 1);

    char valor_remover = 'B';
    lista_remover_no(&lista, valor_remover);

    printf("Lista final: ");
    No* atual = lista;
    while (atual != NULL) {
        printf("%c ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");

    lista_libera_memoria(lista);

    return 0;
}