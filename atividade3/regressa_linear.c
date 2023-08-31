#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double x;
    double y;
} Ponto;


void calcularRegressaoLinear(Ponto *pontos, int n, double *a, double *b) {
    double soma_x = 0.0;
    double soma_y = 0.0;
    double soma_xy = 0.0;
    double soma_x2 = 0.0;

    for (int i = 0; i < n; i++) {
        soma_x += pontos[i].x;
        soma_y += pontos[i].y;
        soma_xy += pontos[i].x * pontos[i].y;
        soma_x2 += pontos[i].x * pontos[i].x;
    }

    *a = (n * soma_xy - soma_x * soma_y) / (n * soma_x2 - soma_x * soma_x);
    *b = (soma_y - *a * soma_x) / n;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo.csv\n", argv[0]);
        return 1;
    }

    
    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    
    int numLinhas = 0;
    char linha[100];  

    while (fgets(linha, sizeof(linha), arquivo)) {
        numLinhas++;
    }

    
    Ponto *pontos = (Ponto *)malloc(numLinhas * sizeof(Ponto));

    
    fseek(arquivo, 0, SEEK_SET);

   
    for (int i = 0; i < numLinhas; i++) {
        fgets(linha, sizeof(linha), arquivo);
        sscanf(linha, "%lf,%lf", &pontos[i].x, &pontos[i].y);
    }

    
    fclose(arquivo);

    
    double a, b;
    calcularRegressaoLinear(pontos, numLinhas, &a, &b);

    
    printf("Coeficiente angular (a): %lf\n", a);
    printf("Coeficiente linear (b): %lf\n", b);

    
    free(pontos);

    return 0;
}
