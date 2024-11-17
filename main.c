#include <stdio.h>
#include <stdlib.h>

void povoa_historiograma(char** h, int valores[], int categoria) {
    // Povoa a categoria com '*' correspondente ao valor
    for (int i = 0; i < valores[categoria]; i++) {
        h[categoria][i] = '*';
    }
}

void imprimir_historiograma(char** h, int valores[], int categorias) {
    for (int i = 0; i < categorias; i++) {
        printf("%d", valores[i]);
        for (int j = 0; j < valores[i]; j++) {
            printf("%c", h[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int categorias;
    scanf("%d", &categorias);

    int valores[categorias];
    char* historiograma[categorias];

    for (int i = 0; i < categorias; i++) {
        scanf("%d", &valores[i]);

        if (valores[i] == 0) {
            historiograma[i] = NULL;
        } else {
            // Aloca memória suficiente para o número de asteriscos
            historiograma[i] = (char*)malloc(valores[i] * sizeof(char));
            povoa_historiograma(historiograma, valores, i);
        }
    }

    imprimir_historiograma(historiograma, valores, categorias);

    // Libera a memória alocada
    for (int i = 0; i < categorias; i++) {
        if (historiograma[i] != NULL)
            free(historiograma[i]);
    }

    return 0;
}
