#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho, **matriz, i,j, valor;

    printf("Informe o tamanho N da matriz: ");
    scanf("%d", &tamanho);

    matriz = calloc(tamanho, sizeof(int *));

    if(matriz == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    for(i=0;i<tamanho;i++)
    {
        matriz[i] = calloc(tamanho, sizeof(int));
    }

    for(i=0;i<tamanho;i++)
    {
        for(j=0;j<tamanho;j++)
        {
            printf("MAT[%d][%d]: ",i,j);
            scanf("%d", &valor);
            if(valor % 2 == 0)
            {
                matriz[i][j] = valor;
            }else
            {
                matriz[i][j] = 0;
            }
        }
    }

    for(i=0;i<tamanho;i++)
    {
        for(j=0;j<tamanho;j++)
        {
            printf("MAT[%d][%d]: %d\n",i,j, matriz[i][j] );
        }
    }



    return 0;
}
