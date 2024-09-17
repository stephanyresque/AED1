#include <stdio.h>
#include <stdlib.h>

int fibonacci(int num)
{
    if(num == 0)
    {
        return 0;
    }else if(num == 1)
    {
        return 1;
    }else
    {
        return fibonacci(num - 1) + fibonacci(num -2);
    }
}


int main()
{

    int numero, n;

    printf("Informe o numero da sequencia para calcular o Fibonacci: ");
    scanf("%d", &numero);

    for(n=0;n<=numero;n++)
    {
        printf("%d ", fibonacci(n));
    }


    return 0;
}
