#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;

    printf("Enderecos\n");
    printf("VAR i: %d\n", &i);
    printf("VAR j: %d\n", &j);
    printf("----------------\n");

    if( &i > &j)
    {
        printf("Maior endereco: %d\n", &i);
    }else
    {
        printf("Maior endereco: %d\n", &j);
    }

    return 0;
}
