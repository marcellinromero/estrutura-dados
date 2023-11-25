#include <stdio.h>
#include "tabela_hash.h"

int main() {
    hash_table_put("produto123", "Notebook");
    hash_table_put("produto456", "Smartphone");
    hash_table_put("produto789", "Impressora");

    printf("Descrição do produto 'produto123': %s\n", hash_table_get("produto123"));
    printf("Descrição do produto 'produto456': %s\n", hash_table_get("produto456"));
    printf("Descrição do produto 'produto789': %s\n", hash_table_get("produto789"));

    hash_table_remove("produto456");

    printf("Descrição do produto 'produto456' após remoção: %s\n", hash_table_get("produto456"));

    return 0;
}