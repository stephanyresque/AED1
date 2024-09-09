#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, *vet, i;

    N = 0;

    while(N<=0)
    {
        printf("Digite um valor N: ");
        scanf("%d", &N);

        if(N <= 0)
        {
            printf("Valor invalido\n");
        }
    }

    vet = calloc(N, sizeof(int));

    if(vet == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }


    for(i=0;i<N;i++)
    {
        printf("vet[%d]: ", i);
        scanf("%d", &(*(vet+i)));

        if( (*(vet+i)) < 2 )
        {
            *(vet +i) = 2;
        }
    }

    system("cls");

    for(i=0;i<N;i++)
    {
        printf("vet[%d]: %d\n", i, *(vet+i));

    }

    return 0;
}
