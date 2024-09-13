#include <stdio.h>
#include <stdlib.h>

int binario(int n)
{
    if (n==0)
    {
        return 0;
    }

    binario(n/2);
    printf("%d", n%2);
}
int main()
{
    int k, *numeros;

    printf("Informe quantos numeros: ");
    scanf("%d", &k);

    numeros = calloc(k, sizeof(int));

    printf("Informe os numeros:\n");
    for(int i = 0; i<k; i++)
    {
        scanf("%d", &(*(numeros + i)));
    }

    for(int i = 0; i < k; i++)
    {
        binario( *(numeros+i) );
        printf("\n");
    }
    return 0;
}
