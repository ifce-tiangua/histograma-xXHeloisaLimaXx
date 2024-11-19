
#include <stdio.h>
#include <stdlib.h>

void exibir_histograma(char* categorias[], int quantidades[], int total) {
    for (int i = 0; i < total; i++) {
        printf("%d ", quantidades[i]);
        for (int j = 0; j < quantidades[i]; j++) {
            printf("%c", categorias[i][j]);
        }
        printf("\n");
    }
}

void preencher_histograma(char *categorias[], int quantidade, int indice) {
    for (int i = 0; i < quantidade; i++) {
        if (categorias[indice][i] >= 0) {
            categorias[indice][i] = '*';
        }
    }
    if (categorias[indice][quantidade]) {
        categorias[indice][quantidade] = '\0';
    }
}

int main() {
    int total_categorias;

    scanf("%d",