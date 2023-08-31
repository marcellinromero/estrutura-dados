#include <stdio.h>
#include <stdlib.h>

int is_prime(int n) {
    if (n <= 1) {
        return 0;  
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;  
        }
    }
    return 1;  
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }
    
    int numero = atoi(argv[1]);
    
    if (is_prime(numero)) {
        printf("1 - O numero %d eh primo.\n", numero);
    } else {
        printf("0 - O numero %d nao eh primo.\n", numero);
    }
    
    return 0;
}
