#include <stdio.h>
#include <stdlib.h>

void povoa_historiograma(char** h, int valores[], int categoria) {
    for (int i = 0; i < valores[categoria]; i++) {
        h[categoria][i] = '*';
    }
}

void imprimir_historiograma(char** h, int valores[], int categorias) {
    for (int i = 0; i < categorias; i++) {
        printf("%d", valores[i]);
        if (valores[i] > 0) {
            for (int j = 0; j < valores[i]; j++) {
                printf("%c", h[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int categorias;
    scanf("%d", &categorias);

    if (categorias <= 0) {
        return 0; // Termina para entradas inválidas
    }

    int valores[categorias];
    char* historiograma[categorias];

    for (int i = 0; i < categorias; i++) {
        scanf("%d", &valores[i]);

        if (valores[i] < 0) {
            valores[i] = 0; // Tratar valores negativos como zero
        }

        if (valores[i] == 0) {
            historiograma[i] = NULL;
        } else {
            historiograma[i] = (char*)malloc(valores[i] * sizeof(char));
            povoa_historiograma(historiograma, valores, i);
        }
    }

    imprimir_historiograma(historiograma, valores, categorias);

    for (int i = 0; i < categorias; i++) {
        if (historiograma[i] != NULL) {
            free(historiograma[i]);
        }
    }

    return 0;
}
