#include <stdio.h>
#include <stdlib.h>

void imprime_histograma(char* categorias[], int quantidades[], int total) {

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

    scanf("%d", &total_categorias);

    if (total_categorias <= 0) {
        printf("vazio\n");
        return 0;
    }

    int valores[total_categorias];
    char* histograma[total_categorias];

    for (int i = 0; i < total_categorias; i++) {

        scanf("%d", &valores[i]);

        if (valores[i] == 0) {

            histograma[i] = NULL;

        } else {
            histograma[i] = (char*)malloc((valores[i] + 1) * sizeof(char));

            preencher_histograma(histograma, valores[i], i);
        }
    }

    imprime_histograma(histograma, valores, total_categorias);

    for (int i = 0; i < total_categorias; i++) {
        free(histograma[i]);
    }
    return 0;
}