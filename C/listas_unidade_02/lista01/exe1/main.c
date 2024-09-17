#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"

int main()
{
    Cubo *meu_cubo;

    meu_cubo = create(5);

    area(meu_cubo);
    printf("\n");
    volume(meu_cubo);

    return 0;
}