#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, i, j, valor_original;
    int **matriz;

    printf("Informe a dimensao da matriz: ");
    scanf("%d", &m);

    matriz = calloc(m, sizeof(int*));

    if(matriz == NULL){
        printf("Erro ao alocar matriz\n");
        return 1;
    }

    for(i=0;i<m;i++){
        matriz[i] = calloc(m,sizeof(int));
    }

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            printf("[%d][%d]: ", i, j);
            scanf("%d", &valor_original);
            matriz[i][j] = valor_original * 5;
        }
    }

    system("cls");

    printf("Matriz alterada:\n");
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            printf("%d |", matriz[i][j]);
        }
        printf("\n");
    }  
    printf("--------------------\n");
    printf("Matriz original:\n");
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            printf("%d |", (matriz[i][j])/5 );
        }
        printf("\n");
    }  

    for(int i = 0; i < m; i++)
    {
        free(matriz[i]);

    }
    free(matriz);


    return 0;
}