#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho, **matriz, i,j, primeiro_valor;

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
    printf("Informe o primeiro valor da matriz: ");
    scanf("%d", &primeiro_valor);

    matriz[0][0] = primeiro_valor;

    for(i=0;i<tamanho;i++)
    {
        for(j=1;j<tamanho;j++)
        {
            primeiro_valor = primeiro_valor*2;
            if(i > j)
            {
                matriz[i][j] = 0;
            }else
            {
                matriz[i][j] = primeiro_valor;
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
