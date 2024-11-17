#include <stdio.h>
#include <stdlib.h>

void povoa_historiograma(char* h[], int valor, int categoria){
    //povoar com * a categoria com seu respectivo valor\\
    
    for(int i = 0; i < valor; i++){
        h[categoria][i] = '*';

}
}

void imprimir_historiagrama(char* h[], int valores[], int categorias){
    
    for(int i = 0; i < categorias; i++){
    int j;
        printf("%d",valores[i]);
        for(int j = 0; j < valores[i]; j++){
        printf("%c", h[i][j]);
    }
    printf("\n");
        
    }
    
}

int main(){
    int categorias;
    scanf("%d", &categorias);
    
    int valores[categorias];
    char *historiograma[categorias];
    
    for(int i = 0; i < categorias; i++){
        scanf("%d", &valores[i]);
        
        if(valores[i] == 0){
            historiograma[i] = NULL;
        }else{
            historiograma[i] = (char *)malloc(valores[i] * sizeof(char));
            povoa_historiograma(historiograma,valores[i], i);
            }
            
        }
        imprimir_historiagrama(historiograma, valores, categorias);
for(int i = 0; i < categorias; i++)
If (historiograma[i] !=NULL)
free(historiograma[i]);

        return 0 ;
    }
