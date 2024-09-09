#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho, **matriz, i,j;

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
            if(i==j)
            {
                matriz[i][j] = 0;
            }else if(i > j)
            {
                matriz[i][j] = -1;
            }else
            {
                matriz[i][j] = 1;
            }
        }
    }

    for(i=0;i<tamanho;i++)
    {
        for(j=0;j<tamanho;j++)
        {
            printf("%d ", matriz[i][j] );
        }
        printf("\n");
    }



    return 0;
}
