#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[] = {1,2,3,4,5};
    int i;

    for(i=0;i<5;i++)
    {
        printf("vet[%d]: %d\n", i, 2*(*(vet+i)) );
    }

    return 0;
}
