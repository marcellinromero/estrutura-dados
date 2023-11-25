#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct {
    char* chave;
    char* dado;
} Registro;

Registro tabela[TABLE_SIZE];

int hash(char* chave) {
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % TABLE_SIZE;
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);
    
    if (hash_table_contains(chave)) {
        free(tabela[index].dado);
    } else {
        tabela[index].chave = strdup(chave);
    }

    tabela[index].dado = strdup(dado);
}

char* hash_table_get(char* chave) {
    int index = hash(chave);
    
    if (hash_table_contains(chave)) {
        return tabela[index].dado;
    } else {
        return NULL;
    }
}

int hash_table_contains(char* chave) {
    int index = hash(chave);
    
    if (tabela[index].chave != NULL && strcmp(tabela[index].chave, chave) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void hash_table_remove(char* chave) {
    int index = hash(chave);

    if (hash_table_contains(chave)) {
        free(tabela[index].chave);
        free(tabela[index].dado);
        tabela[index].chave = NULL;
        tabela[index].dado = NULL;
    }
}
