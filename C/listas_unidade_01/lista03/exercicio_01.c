#include <stdio.h>
#include <stdlib.h>

int sequencia(int n)
{
    if (n <= 0)
    {
        return;
    }
    sequencia(n-1);
    printf("%d ", n);

}

int main()
{
    int n;

    printf("Informe a sequencia de naturais: ");
    scanf("%d", &n);

    sequencia(n);

    return 0;
}
