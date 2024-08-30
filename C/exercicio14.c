#include <stdio.h>
#include <stdlib.h>


int main()
{
    int **matriz, linhas, colunas, M, valor;

    printf("Informe o tamanho M da matriz: ");
    scanf("%d", &M);
    linhas = M;
    colunas = M;

    matriz = calloc(linhas, sizeof(int *));

    if(matriz == NULL)
    {
        printf("Erro ao alocar memoria");
        return 1;
    }

    for(int i = 0; i < linhas; i++)
    {
        matriz[i] = calloc(colunas, sizeof(int));
    }

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            valor = 0;
            printf("[%d][%d]: ", i+1,j+1);
            scanf("%d", &valor);
            matriz[i][j] = valor * 5;
        }

    }

    system("cls");
    printf("Matriz original\n");
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            printf("%d |", (matriz[i][j])/5);
        }
        printf("\n");
    }

    printf("Matriz modificada\n");
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            printf("%d |", (matriz[i][j]));
        }
        printf("\n");
    }

    return 0;
}
