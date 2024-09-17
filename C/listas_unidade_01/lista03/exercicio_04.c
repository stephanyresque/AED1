#include <stdio.h>
#include <stdlib.h>

int reverso(int n, int j)
{
    if (n==0)
    {
        return j;
    }

    j = j * 10 + (n%10);

    return reverso(n/10, j);

}

int main()
{
    int numero;

    printf("Informe um numero para ser invertido: ");
    scanf("%d", &numero);
    printf("%d", reverso(numero, 0));
    return 0;
}
