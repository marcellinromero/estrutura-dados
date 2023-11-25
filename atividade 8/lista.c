#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void lista_inicializar(No** L) {
    *L = NULL;
}

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int contador = 0;
    No* atual = L;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            contador++;
        }
        atual = atual->proximo;
    }
    return contador;
}

void lista_imprimir_inversa(No* L) {
    if (L == NULL) {
        return;
    }
    lista_imprimir_inversa(L->proximo);
    printf("%c ", L->valor);
}

void lista_inserir_no_i(No* L, int i, char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    No* atual = L;
    int contador = 0;
    while (contador < i && atual->proximo != NULL) {
        atual = atual->proximo;
        contador++;
    }
    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;
}

void lista_remover_no_i(No* L, int i) {
    No* atual = L;
    int contador = 0;
    while (contador < i && atual->proximo != NULL) {
        atual = atual->proximo;
        contador++;
    }
    if (atual->proximo != NULL) {
        No* temp = atual->proximo;
        atual->proximo = temp->proximo;
        free(temp);
    }
}

void lista_remover_no(No** L, char valor_busca) {
    No* atual = *L;
    No* anterior = NULL;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            if (anterior != NULL) {
                anterior->proximo = atual->proximo;
            } else {
                *L = atual->proximo;
            }
            free(atual);
            atual = (anterior != NULL) ? anterior->proximo : *L;
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

void lista_libera_memoria(No* L) {
    No* atual = L;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}