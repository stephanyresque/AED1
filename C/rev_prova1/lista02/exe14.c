// Escreva um programa que leia um inteiro N e crie uma matriz alocada dinamicamente contendo
// N linhas e N colunas. Essa matriz deve conter o valor 0 na diagonal principal, o valor 1 nos
// elementos acima da diagonal principal e o valor −1 nos elementos abaixo da diagonal principal.

#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, **matriz, i, j;

    printf("Informe o tamanho n da matriz: ");
    scanf("%d", &n);

    matriz = calloc(n, sizeof(int *)); //linhas

    if(matriz == NULL){
        printf("Erro na alocacao.\n");
        return 1;
    }

    for(i=0;i<n;i++){ //colunas
        matriz[i] = calloc(n, sizeof(int));
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==i){
                matriz[i][j] = 0;
            }else if(i < j){
                matriz[i][j] = 1;
            }else if(i > j){
                matriz[i][j] = -1;
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d  |", matriz[i][j]);
        }
        printf("\n");
    }


    for(i=0;i<n;i++){
        free(matriz[i]);
    }
    free(matriz);



    return 0;
}