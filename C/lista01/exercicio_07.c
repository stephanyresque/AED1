#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, tam, *vet;

    printf("Qual o tamanho do vetor: ");
    scanf("%d", &tam);

    vet = calloc(tam, sizeof(int));

    if(vet == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    for(i=0;i<tam;i++)
    {
        printf("vet[%d]: ", i+1);
        scanf("%d", &(*(vet+i)));
    }

    system("cls");

    for(i=0;i<tam;i++)
    {
        printf("vet[%d]: %d\n", i+1, *(vet+i));

    }

    return 0;
}
